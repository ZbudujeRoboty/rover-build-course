#include "FablabL298Driver.h"
#include <Servo.h>

#define FL_LEFT     0
#define FR_LEFT     0
#define RL_LEFT     0
#define RR_LEFT     0
#define FL_RIGHT    0
#define FR_RIGHT    0
#define RR_RIGHT    0
#define RL_RIGHT    0
#define FL_STRAIGHT 0
#define FR_STRAIGHT 0
#define RL_STRAIGHT 0
#define RR_STRAIGHT 0

class ServoTP: public Servo {
public:
  void write(int);
  void attach(int, int,int);
private:
  int lewa_granica;
  int prawa_granica;
};

// Serial pins
const int RX_PIN = 0;
const int TX_PIN = 1;

// Motor pins
const int ENA_PIN_L = 3;
const int IN1_PIN_L = 2; 
const int IN2_PIN_L = 4;
const int ENA_PIN_R = 5;
const int IN1_PIN_R = 7; 
const int IN2_PIN_R = 8;

// Servo pins
const int SERVO_FL = 6;
const int SERVO_FR = 9;
const int SERVO_RL = 10;
const int SERVO_RR = 11;

FablabL298Driver motor_L(ENA_PIN_L, IN1_PIN_L, IN2_PIN_L);
FablabL298Driver motor_R(ENA_PIN_R, IN1_PIN_R, IN2_PIN_R);

ServoTP servo_FL;
ServoTP servo_FR;
ServoTP servo_RL;
ServoTP servo_RR;

/* DOSTĘPNE FUNKCJE!
 *
 * Serial.println(tekst);       tekst - jakiś ciąg znaków, np: "Ala ma kota.", kontroler printuje słowa na monitor portu szeregowego 
 * moje_serwo.write(x);         x - kąt serwa w procentach; funkcja ustawia serwo: -100 to max w lewo, +100 to max w prawo, 0 to środek
 * delay(x);                    x - czas w milisekundach (tysięczna sekundy), program poczeka tyle czasu z dalszym wykonywaniem
 * moj_silnik.backward();       ustawia kierunek silnika do tyłu
 * moj_silnik.goPercentage(x);  x - procent 0-100. ustawia prędkość silnika na daną część maksymalnej szybkości, np. 50 to połowa najszybszej prędkości
 * moj_silnik.forward();        ustawia kierunek silnika do przodu
 * moj_silnik.stop();           zatrzymuje pracę silnika i hamuje go
 *
 */

void setup() {
  // Initialize the motor
  motor_L.begin();
  motor_R.begin();
  servo_FL.attach(SERVO_FL, FL_RIGHT, FL_LEFT);
  servo_FR.attach(SERVO_FR, FR_RIGHT, FR_LEFT);
  servo_RL.attach(SERVO_RL, RL_RIGHT, RL_LEFT);
  servo_RR.attach(SERVO_RR, RR_RIGHT, RR_LEFT);
  Serial.begin(9600);
}

void loop() {

  // 1 pojechac do przodu silnikami z szybkością 50%

  // 2 skrecic w lewo 50%
 
  // 3 skrecic w prawo 75%

  // 4 pojechac do tyłu z szybkością 30%

  // 5 obkręcić się w lewo

  // 6 obkręcić się w prawo

  // 7 w lewo 50% i do przodu 50%

  // 8 w prawo 50% i do przodu 50%

  delay(100);
}

// -100 100 = max lewo max prawo
void ServoTP::write(int value) {
  if( value > 100 )
    value = 100;
  else if ( value < -100 )
    value = -100;
  
  value = (value+100) * (prawa_granica - lewa_granica) / (100+100) + lewa_granica;
  long value_us = ((long)value * (2400-550)) / 170 + 550;
  this->writeMicroseconds((int)(value_us));
  Serial.println(value);
  Serial.println(value_us);
}

void ServoTP::attach(int pin, int prawa, int lewa) {
  prawa_granica = prawa;
  lewa_granica = lewa;
  ((Servo*)this)->attach(pin);
}
