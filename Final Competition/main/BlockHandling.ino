void set_lift_servo(int angle)
{
  angle = constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE);
  myServoLift.write(angle);
}

void set_grab_servo(int angle)
{
  angle = constrain(angle, GRABBER_MIN_ANGLE, GRABBER_MAX_ANGLE);
  myServoGrab.write(angle);
}

bool scan_and_lift_block()
{
  read_ultrasonic_front();
  if (distance_front <= colour_sense_distance)
  {
    while (distance_front > 8)
    {
      go_straight_slow();
      read_ultrasonic_front();
      read_all_line_sensors();
    }

    stop(); // Grab Procedure
    set_grab_servo(GRAB_REST_ANGLE);
    delay(200);
    set_lift_servo(45);
    delay(200);
    set_lift_servo(55);
    delay(200);
    go_straight_slow();
    delay(900);
    stop();
    set_grab_servo(GRAB_ANGLE);
    delay(200);
    activate_color_sensor();
    set_lift_servo(SERVO_REST_ANGLE);
    delay(200);

    return true;
  }

  return false;
}