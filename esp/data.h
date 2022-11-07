#pragma once

#define HEADER    "hong"
#define TRAILER   "long"

#define PROJECT_ID        "do-an-2-ute-default-rtdb"
#define BEDROOM_DATA      "BED_ROOM/data"
#define BEDROOM_NHIETDO   "BED_ROOM/nhiet_do"
#define BEDROOM_DOAM      "BED_ROOM/do_am"
#define BEDROOM_KHIGAS    "BED_ROOM/khi_ga"
#define BEDROOM_ANHSANG   "BED_ROOM/cb_as"
#define BEDROOM_TIVI      "BED_ROOM/ti_vi"
#define BEDROOM_MAYLANH   "BED_ROOM/may_lanh"
#define BEDROOM_DEN       "BED_ROOM/den"

#define L1  D5
#define L2  D6
#define L3  D7
#define L4  D8

String ssid[] = { "Chinh Nghiep", "" }, password[] = { "03897.@!", "" };
uint8_t temp = 0, hum = 0;
uint16_t gas = 0;
uint64_t _time = 0;
bool isUpdateLcd = false, isUpdateLed = false, as = false, tivi = false, maylanh = false, den = false;
