// Załączanie bibliotek
#include "FablabL298Driver.h"
#include <Servo.h>

// Dostosowanie klasy serwo
class ServoTP: public Servo {
public:
  void write(int);
};

// Definicja kątów serwa
#define LEWO ???
#define W_PRAWO ???

// Zmienne pinów sterownika silnika
int ENA_PIN = ?; // pwm ~
int IN1_PIN = ?; 
int IN2_PIN = ?;

// Pin serwomechanizmu
int SERWO_PIN = ?; // pwm ~

// Tworzenie obiektów
FablabL298Driver IMIE_MOJEGO_SILNIKA(ENA_PIN, IN1_PIN, IN2_PIN);
ServoTP IMIE_MOJEGO_SERWOMECHANIZMU;

void setup() {
  Serial.begin(9600);
  IMIE_MOJEGO_SILNIKA.begin();
  IMIE_MOJEGO_SERWOMECHANIZMU.attach(SERWO_PIN);
}

void loop() {

  Serial.println("tekst");
  
  IMIE_MOJEGO_SILNIKA.backward();
  IMIE_MOJEGO_SILNIKA.forward();
  IMIE_MOJEGO_SILNIKA.stop();
  IMIE_MOJEGO_SILNIKA.goPercentage(???);
  
  IMIE_MOJEGO_SERWOMECHANIZMU.write(LEWO);

  delay(???);
  
  // ...
  // ...
  // ...

}

// Dostosowanie klasy serwo
void ServoTP::write(int value) {
  long value_us = ((long)value * (2400-550)) / 170 + 550;
  this->writeMicroseconds((int)(value_us));
  Serial.println(value);
  Serial.println(value_us);
}
