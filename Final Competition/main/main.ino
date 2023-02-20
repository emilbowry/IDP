#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Servo.h>
#include <WiFiNINA.h>

// Headers for module parameters in folder main/Headers/.
#include "Headers/Ultrasonic.h"
#include "Headers/Buttons.h"
#include "Headers/Motors.h"
#include "Headers/ColourSensor.h"
#include "Headers/ServoController.h"
#include "Headers/Led.h"
#include "Headers/LineSensors.h"
#include "Headers/BlockHandling.h"
#include "Headers/Timer.h"
#include "Headers/Wifi.h"
#include "Headers/StateController.h"

void setup()
{

  Serial.begin(9600);
  startwifi();
  set_pins();
  AFMS.begin();
  initialise_output_pins();
  initialise_servo_angles();
  delay(500);
}

void loop()
{
  run_wifi();
  serial();

  time = millis() - start_time; // time since leaving start box

  read_all_line_sensors();

  switch (state)
  {
  case 0:
    start_state();
    break;
  case 1: 
    box_start_state();
    break;
  case 2: 
    line_following_state();
    break;
  case 21:
    side_detection_state();
    break;
  case 22:
    side_block_pickup();
    break;
  case 3:
    pickup_block_state();
    break;
  case 4: 
    reverse_branch_state();
    break;
  case 5: 
    tunnel_state();
    break;
  case 6: 
    go_truck_area_state();
    break;
  case 7: 
    drop_block_state();
    break;
  case 8: 
    return_line_state();
    break;
  case 9: 
    return_to_start_state();
    break;
  case 10: 
    stop_state();
    break;

  //test states
  case 11: 
    follow_line_test();
    break;
  case 12:
    ultrasonic_test_state();
    break;
  case 13:
    line_reader_test_state();
    break;
  }
}
