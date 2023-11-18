// Załączanie bibliotek
#include "FablabL298Driver.h"
#include <Servo.h>

// Dostosowanie klasy serwo
class ServoTP: public Servo {
public:
  void write(int);
};

// Definicja kątów serwa
#define W_LEWO    25
#define W_PRAWO   115
#define PROSTO    70

// Zmienne pinów sterownika silnika
int ENA_PIN = 3; // pwm ~
int IN1_PIN = 2; 
int IN2_PIN = 4;

// Pin serwomechanizmu
int SERWO_PIN = 9; // pwm ~

// Tworzenie obiektów
FablabL298Driver moj_silnik(ENA_PIN, IN1_PIN, IN2_PIN);
ServoTP moje_serwo;

void setup() {
  Serial.begin(9600);
  moj_silnik.begin();
  moje_serwo.attach(SERWO_PIN);
}

void loop() {

  Serial.println("Do tyłu 100%");
  moj_silnik.backward();
  moj_silnik.goPercentage(100);
  delay(1000);
  
  Serial.println("Do tyłu 50%");
  moj_silnik.backward();
  moj_silnik.goPercentage(50);
  delay(1000);
  
  Serial.println("Do przodu 15%");
  moj_silnik.forward();
  moj_silnik.goPercentage(15);
  delay(1000);

  Serial.println("Do przodu 100%");
  moj_silnik.forward();
  moj_silnik.goPercentage(100);
  delay(1000);

  Serial.println("Stop!");
  moj_silnik.stop();
  delay(1000);
  
  Serial.println("Skręt w lewo");
  moje_serwo.write(W_LEWO);
  delay(1000);
  
  Serial.println("Skręt w prawo");
  moje_serwo.write(W_PRAWO);
  delay(1000);
  
  Serial.println("Skręt na środek");
  moje_serwo.write(PROSTO);
  delay(1000);  
}

// Dostosowanie klasy serwo
void ServoTP::write(int value) {
  long value_us = ((long)value * (2400-550)) / 170 + 550;
  this->writeMicroseconds((int)(value_us));
  Serial.println(value);
  Serial.println(value_us);
}
