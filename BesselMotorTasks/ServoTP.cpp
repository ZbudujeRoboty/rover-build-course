#include "ServoTP.h"
// #include <HardwareSerial.h>

extern ServoTP servo_FL;
extern ServoTP servo_FR;
extern ServoTP servo_RR;
extern ServoTP servo_RL;

// -100 100 = max lewo max prawo
void ServoTP::write(int value) {
  int value_cpy = value;
  if( value > 100 )
    value = 100;
  else if ( value < -100 )
    value = -100;
  
  value = (value+100) * (prawa_granica - lewa_granica) / (100+100) + lewa_granica;
  long value_us = ((long)value * (2400-550)) / 170 + 550;
  this->writeMicroseconds((int)(value_us));
  // if(this == &servo_FR)
    // Serial.println(value_cpy);
}

void ServoTP::attach(int pin, int prawa, int lewa) {
  prawa_granica = prawa;
  lewa_granica = lewa;
  (this)->attach(pin);
}

