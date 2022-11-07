#include "data.h"
#include "rfid_sensor.h"
#include "uart.h"
#include "control.h"

void setup() {
  rfid_sensor::setup();
  uart::setup();
  control::setup();
}

void loop() {
  uart::writeUART();

  if (rfid_sensor::readBT(1) || rfid_sensor::checkFakeCard(valid_id)) // cua
  {
    cua = !cua;
    if (cua) control::controlServo(DOOROPEN);
    else control::controlServo(DOORCLOSE);
  }
  if (rfid_sensor::readBT(2)) // led ss
  {
    ledss = (ledss + 1) & 3;
    control::controlLedSS(ledss);
  }
  if (rfid_sensor::readBT(3)) // quat
  {
    quat = (quat + 1) & 3;
    control::controlMotor(quat);
  }
  if (rfid_sensor::readBT(4)) // tivi
  {
    tivi = !tivi;
  }
  if (rfid_sensor::readBT(5)) // may lanh
  {
    maylanh = !maylanh;
  }
  if (rfid_sensor::readBT(6)) // den
  {
    den = !den;
  }
}
