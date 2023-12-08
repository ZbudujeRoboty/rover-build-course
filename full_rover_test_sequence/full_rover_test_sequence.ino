// Załączanie bibliotek
#include "FablabL298Driver.h"
#include <Servo.h>

// Dostosowanie klasy serwo
class ServoTP: public Servo {
public:
  void write(int);
};

// Zmienne pinów sterownika silnika
int ENA_PIN = 3; // pwm ~
int IN1_PIN = 2; 
int IN2_PIN = 4;
int IN3_PIN = 8;
int IN4_PIN = 7; 
int ENB_PIN = 5; // pwm ~

// Pin serwomechanizmu
int SERWO_LP = 11; // pwm ~
int SERWO_PP = 10; // pwm ~
int SERWO_LT = 9; // pwm ~
int SERWO_PT = 6; // pwm ~


// Tworzenie obiektów
FablabL298Driver prawe_silniki(ENA_PIN, IN1_PIN, IN2_PIN);
FablabL298Driver lewe_silniki(ENB_PIN, IN3_PIN, IN4_PIN);
ServoTP moje_serwo_lp;
ServoTP moje_serwo_pp;
ServoTP moje_serwo_lt;
ServoTP moje_serwo_pt;

void setup() {
  Serial.begin(9600);
  prawe_silniki.begin();
  lewe_silniki.begin();
  moje_serwo_lp.attach(SERWO_LP);
  moje_serwo_pp.attach(SERWO_PP);
  moje_serwo_lt.attach(SERWO_LT);
  moje_serwo_pt.attach(SERWO_PT);
}

void loop() {

  // USTAW SERWA NA PRZÓD
  moje_serwo_lp.write(70);
  moje_serwo_pp.write(115);
  moje_serwo_lt.write(115);
  moje_serwo_pt.write(70);
  
  // JAZDA JAZDA JAZDA PRZÓD
  Serial.println("JAZDA DO PRZODU");
  lewe_silniki.forward();
  prawe_silniki.forward();
  lewe_silniki.goPercentage(100);
  prawe_silniki.goPercentage(100);
  delay(1000);
 
}

// Dostosowanie klasy serwo
void ServoTP::write(int value) {
  long value_us = ((long)value * (2400-550)) / 170 + 550;
  this->writeMicroseconds((int)(value_us));
  Serial.println(value);
  Serial.println(value_us);
}
