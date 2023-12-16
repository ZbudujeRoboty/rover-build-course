#ifndef _SERVOTP_H_
#define _SERVOTP_H_

#include <Servo.h>

class ServoTP: public Servo {
public:
  void write(int);
  void attach(int, int,int);
  using Servo::attach;
private:
  int lewa_granica;
  int prawa_granica;
};

#endif /* _SERVOTP_H_ */
