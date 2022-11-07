#pragma once

#include "firebase.h"
#include "StringSplitter.h"
#include "control.h"

namespace uart
{
void setup()
{
  Serial.begin(9600);
}

bool checkStatus(const auto& after, auto& before)
{
  if (after != before)
  {
    before = after;
    return false;
  }

  return true;
}

void readUART()
{
  // Packet format: hong-nhietdo-doam-khigas-as-bt4-bt5-bt6-long

  String data_str;
  if (Serial.available() > 0) data_str = Serial.readStringUntil('\n');

  StringSplitter *splitter = new StringSplitter(data_str, '-', 9);
  uint8_t itemCount = splitter->getItemCount();

  String header = splitter->getItemAtIndex(0);
  String trailer = splitter->getItemAtIndex(itemCount - 1);

  if (header == HEADER && trailer == TRAILER)
  {
    auto _temp = splitter->getItemAtIndex(1).toInt();
    auto _hum = splitter->getItemAtIndex(2).toInt();
    auto _gas = splitter->getItemAtIndex(3).toInt();
    auto _as = splitter->getItemAtIndex(4).toInt();
    auto _tivi = splitter->getItemAtIndex(5).toInt();
    auto _maylanh = splitter->getItemAtIndex(6).toInt();
    auto _den = splitter->getItemAtIndex(7).toInt();

    if (millis() - _time >= 5000)
    {
      control::controlLcdUploadFB(true);
      firebase::setData(BEDROOM_DATA, data_str);
      control::controlLcdUploadFB(false);
      _time = millis();
    }

    if (!checkStatus(_temp, temp) || !checkStatus(_hum, hum)) isUpdateLcd = true;
    if (abs(_gas - gas) >= 3)
    {
      gas = _gas;
      isUpdateLcd = true;
    }
    if (!checkStatus(_as, as) || !checkStatus(_tivi, tivi) || !checkStatus(_maylanh, maylanh) || !checkStatus(_den, den))
    {
      isUpdateLed = true;
    }
  }

  delete splitter;
}
}
