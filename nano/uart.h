#pragma once

//#include "StringSplitter.h"

namespace uart
{ 
void setup()
{
  Serial.begin(9600);
}

//void readUART()
//{
//  // Packet format: hong-bt4-bt5-bt6-long
//
//  String data_str;
//  if (Serial.available() > 0) data_str = Serial.readStringUntil('\n');
//
//  StringSplitter *splitter = new StringSplitter(data_str, '-', 5);
//  uint8_t itemCount = splitter->getItemCount();
//
//  String header = splitter->getItemAtIndex(0);
//  String trailer = splitter->getItemAtIndex(itemCount - 1);
//
//  if (header == HEADER && trailer == TRAILER)
//  {
//    tivi = splitter->getItemAtIndex(1);
//    maylanh = splitter->getItemAtIndex(2);
//    den = splitter->getItemAtIndex(3);
//  }
//
//  delete splitter;
//}

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
