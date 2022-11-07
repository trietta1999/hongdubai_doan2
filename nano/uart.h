#pragma once

namespace uart
{ 
void setup()
{
  Serial.begin(9600);
}

void writeUART()
{
  // Packet format: hong-nhietdo-doam-khigas-as-bt4-bt5-bt6-long

  uint8_t temp, hum;
  rfid_sensor::readDHT(temp, hum);
  auto gas = rfid_sensor::readMQ();
  auto as = rfid_sensor::readAS();

  String data_str = String(HEADER) + "-" + temp + "-" + hum + "-" + gas + "-" + as + "-" + tivi + "-" + maylanh + "-" + den + "-" + TRAILER + "\n";

  Serial.print(data_str);
}
}
