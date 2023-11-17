#include "Servo.h"

class ServoTP: public Servo {
public:
  void write(int);
};

const int SERVO_PIN = 9;

ServoTP servo;
int i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  servo.attach(SERVO_PIN);
  while (!Serial) {
    ;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    if (i = Serial.parseInt()) {
      servo.write(i);
      
      // Serial.println("XXX");
    }
    // Serial.println(i);
  }

  delay(100);

  // Serial.println(sizeof(int));

  // while (i > 0) {
  //   i--;
  //   digitalWrite(LED_BUILTIN, HIGH);
  //   delay(250);
  //   digitalWrite(LED_BUILTIN, LOW);
  //   delay(250);
  // }
}

void ServoTP::write(int value) {
  long value_us = ((long)value * (2400-550)) / 170 + 550;
  this->writeMicroseconds((int)(value_us));
  Serial.println(value);
  Serial.println(value_us);
}
