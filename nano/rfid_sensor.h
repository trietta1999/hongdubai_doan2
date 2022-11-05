#pragma once

#include <DHT.h>
#include <SPI.h>
#include <MFRC522.h>
#include "control.h"

namespace rfid_sensor
{
DHT dht(DHT_pin, DHT11);
MFRC522 mfrc522(SDA_pin, RST_pin);

void setup()
{
  pinMode(AS_pin, INPUT);
  pinMode(BT1, INPUT_PULLUP);
  pinMode(BT2, INPUT_PULLUP);
  pinMode(BT3, INPUT_PULLUP);
  pinMode(BT4, INPUT_PULLUP);
  pinMode(BT5, INPUT_PULLUP);
  pinMode(BT6, INPUT_PULLUP);

  dht.begin();
  SPI.begin();
  mfrc522.PCD_Init();
}

bool readAS()
{
  return digitalRead(AS_pin);
}

uint16_t readMQ()
{
  return analogRead(MQ_pin);
}

void readDHT(uint8_t& temp, uint8_t& hum)
{
  temp = dht.readTemperature();
  hum = dht.readHumidity();
}

bool readBT(const uint8_t& index)
{
  uint8_t list[7] = { 0, BT1, BT2, BT3, BT4, BT5, BT6};
  bool isPress = false;

  while (!digitalRead(list[index]))
  {
    isPress = true;
    delay(100);
  }

  if (isPress)
  {
    control::controlBuzzer(1);
    delay(200);
    control::controlBuzzer(0);
  }

  return isPress;
}

void readRC522(uint8_t id[]) {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;
  id[0] = mfrc522.uid.uidByte[0];
  id[1] = mfrc522.uid.uidByte[1];
  id[2] = mfrc522.uid.uidByte[2];
  id[3] = mfrc522.uid.uidByte[3];
}

bool checkFakeCard(uint8_t valid_card[][4])
{
  uint8_t id[] = { 0, 0, 0, 0 }, count = 0;
  readRC522(id);

  for (uint8_t row = 0; row < sizeof(valid_card); row++)
  {
    for (uint8_t i = 0; i < 4; i++)
    {
      if (id[i] == valid_card[row][i]) count++;
    }

    if (count == 4)
    {
      control::controlBuzzer(1);
      delay(200);
      control::controlBuzzer(0);
      delay(1000);
      return true;
    }
    else count = 0;
  }

  //  control::controlBuzzer(1);
  //  delay(100);
  //  control::controlBuzzer(0);
  //  delay(200);
  //  control::controlBuzzer(1);
  //  delay(100);
  //  control::controlBuzzer(0);

  return false;
}

}
