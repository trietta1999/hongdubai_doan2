#pragma once

#include <LiquidCrystal_I2C.h>

namespace control
{
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("N.Do D.Am  K.Gas");
}

void controlLcd()
{
  // N.Do-D.Am--K.Gas
  // xx*C--xx%---xxx-
  if (isUpdateLcd)
  {
    lcd.setCursor(0, 1);
    lcd.print(temp);
    lcd.write(0xdf);
    lcd.print("C  ");
    lcd.print(hum);
    lcd.print("%   ");
    lcd.print(gas);
    lcd.print(" ");

    isUpdateLcd = false;
  }
}

void controlLcdUploadFB(const bool& isUpload)
{
  if (isUpload)
  {
    lcd.setCursor(1, 0);
    lcd.write(0xa5);
  }
  else
  {
    lcd.setCursor(1, 0);
    lcd.print(".");
  }
}

void controlLed()
{
  if (isUpdateLed)
  {
    digitalWrite(L1, tivi);
    digitalWrite(L2, maylanh);
    digitalWrite(L3, den);
    digitalWrite(L4, as);

    isUpdateLed = false;
  }
}
}
