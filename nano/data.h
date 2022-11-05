#pragma once

#define SDA_pin   10
#define RST_pin   9

#define AS_pin    8
#define DHT_pin   7
#define MQ_pin    A6

#define BT1   A0  // cua
#define BT2   A1  // led ss
#define BT3   A2  // quat
#define BT4   A3  // tivi
#define BT5   A4  // may lanh
#define BT6   A5  // den

#define MOTOR_pin     3
#define BUZZER_pin    4
#define LEDSS_pin     5
#define SERVO_pin     6

#define DOOROPEN    180
#define DOORCLOSE   0

#define HEADER    "hong"
#define TRAILER   "long"

bool isWriteUART = false, den = false, maylanh = false, tivi = false, cua = false;
uint8_t quat = 0, ledss = 0;

uint8_t valid_id[][4] = { { 0x0b, 0x70, 0x81, 0x22}, { 0xe9, 0xb9, 0xbd, 0x6e} };
