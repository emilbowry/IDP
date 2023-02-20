#ifndef Motors_h
#define Motors_h

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotorL = AFMS.getMotor(3);
Adafruit_DCMotor *myMotorR = AFMS.getMotor(4);
Servo myServoLift;
Servo myServoGrab;

const int max_speed = 255;
int full_turn_speed = -255; // speed of inner motor to turn
int slight_turn_speed = 20;
int large_deviation_speed = 20;
int last_left_speed;
int last_right_speed;
#endif