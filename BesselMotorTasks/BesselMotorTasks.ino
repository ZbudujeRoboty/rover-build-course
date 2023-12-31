#include "FablabL298Driver.h"
#include "ServoTP.h"

// Kątowe skrajne wychylenie dla poszczegolnych serw w lewo i w prawo
#define FL_LEFT       25
#define FL_RIGHT      115
#define FR_LEFT       70
#define FR_RIGHT      160
#define RL_LEFT       160
#define RL_RIGHT      70
#define RR_LEFT       115
#define RR_RIGHT      25

// // Serial pins
// const int RX_PIN = 0;
// const int TX_PIN = 1;

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
  Serial.println(1);
  motor_L.forward();
  motor_R.forward();
  motor_L.goPercentage(50);
  motor_R.goPercentage(50);
  delay(1000);
  
  // 2 skrecic w lewo 50%
  Serial.println(2);
  servo_FL.write(-50);
  servo_FR.write(-50);
  servo_RL.write(-50);
  servo_RR.write(-50);
  delay(1000);
 
  // 3 skrecic w prawo 75%
  Serial.println(3);
  servo_FL.write(75);
  servo_FR.write(75);
  servo_RL.write(75);
  servo_RR.write(75);
  delay(1000);

  // 4 pojechac do tyłu z szybkością 30%
  Serial.println(4);
  motor_L.backward();
  motor_R.backward();
  motor_L.goPercentage(30);
  motor_R.goPercentage(30);
  delay(1000);

  // 5 obkręcić się w lewo
  Serial.println(5);
  motor_L.forward();
  motor_R.forward();
  motor_L.goPercentage(50);
  motor_R.goPercentage(50);
  delay(1000);

  // 6 obkręcić się w prawo z szybkością 50%
  Serial.println(6);
  motor_L.backward();
  motor_R.forward();
  motor_L.goPercentage(50);
  motor_R.goPercentage(50);
  servo_FL.write(100);
  servo_FR.write(-100);
  servo_RL.write(75);
  servo_RR.write(75);
  delay(1000);

  // 7 w lewo 50% i do przodu 50%
  Serial.println(7);
  motor_L.forward();
  motor_R.forward();
  motor_L.goPercentage(50);
  motor_R.goPercentage(50);
  delay(1000);

  // 8 w prawo 50% i do przodu 50%
  Serial.println(8);
  motor_L.forward();
  motor_R.forward();
  motor_L.goPercentage(50);
  motor_R.goPercentage(50);
  delay(1000);

}
