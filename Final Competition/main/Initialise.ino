void set_pins()
{
  pinMode(pin_left_line_sensor, INPUT);
  pinMode(pin_middle_left_line_sensor, INPUT);
  pinMode(pin_middle_right_line_sensor, INPUT);
  pinMode(pin_right_line_sensor, INPUT);
  pinMode(pin_ultrasonic_front_echo, INPUT);
  pinMode(pin_ultrasonic_front_trig, OUTPUT);
  pinMode(pin_ultrasonic_side_echo, INPUT);
  pinMode(pin_ultrasonic_side_trig, OUTPUT);
  pinMode(pin_color_red, INPUT);
  pinMode(pin_red, OUTPUT);
  pinMode(pin_red_block_LED, OUTPUT);
  pinMode(pin_blue_block_LED, OUTPUT);
  pinMode(pin_LED_moving, OUTPUT);
  myServoLift.attach(pin_servo_lift, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
  myServoGrab.attach(pin_servo_grab);
  myServoLift.write(SERVO_MAX_ANGLE);
  myServoGrab.write(GRABBER_MIN_ANGLE);

  pinMode(pin_button_reset, INPUT_PULLUP);
  pinMode(pin_button_stop, INPUT_PULLUP);
  Serial.println("Pins Set");
  attachInterrupt(digitalPinToInterrupt(pin_button_reset), on_reset_press, FALLING);
  attachInterrupt(digitalPinToInterrupt(pin_button_stop), on_stop_press, FALLING);
}

void serial()
{
  if (Serial.available())
  {
    String teststr = Serial.readString(); // read until timeout
    teststr.trim();                       // remove any \r \n whitespace at the end of the String
    String string_val = String(teststr.charAt(1)) + String(teststr.charAt(2)) + String(teststr.charAt(3)) + String(teststr.charAt(4));
    int val = string_val.toInt();

    if (teststr.charAt(0) == 'S')
    { // change robot state with serial
      state = val;
      Serial.print("State is: ");
      Serial.println(val);
    }
    else if (teststr.charAt(0) == 's' && val <= 255 && val >= -255)
    { // change slight_turn_speed with serial
      slight_turn_speed = val;
      Serial.print("Slight turn speed is: ");
      Serial.println(val);
    }
    else if (teststr.charAt(0) == 'l' && val <= 255 && val >= -255)
    { // change large_deviation_speed with serial
      large_deviation_speed = val;
      Serial.print("Large deviation speed is: ");
      Serial.println(val);
    }
    else if (teststr.charAt(0) == 'T')
    {
      turn_time = val;
      Serial.print("turn time is: ");
      Serial.println(val);
    }
    else if (teststr.charAt(0) == 'd')
    {
      turn_delay = val;
      Serial.print("Turn delay is: ");
      Serial.println(val);
    }
    else if (teststr.charAt(0) == 'r')
    {
      ramp_time = val * 1000;
      Serial.print("Turn delay is: ");
      Serial.println(ramp_time);
    }
    else if (teststr.charAt(0) == 'c')
    {
      colour_sense_distance = val;
      Serial.print("Stop dist is: ");
      Serial.println(colour_sense_distance);
    }
    else if (teststr.charAt(0) == 'a')
    { // change servo angle with serial
      // set_lift_servo(val);
      myServoLift.write(val);
      Serial.print("Servo angle is: ");
      Serial.println(val);
    }
    else if (teststr.charAt(0) == 'g')
    { // change servo angle with serial
      set_grab_servo(val);
      Serial.print("Grab angle is: ");
      Serial.println(val);
    }
    else if (teststr.charAt(0) == 'b')
    { // change servo angle with serial
      block_counter = val;
      Serial.print("block counter");
      Serial.println(val);
    }
  }
}

void on_reset_press()
{
  state = 0;
  Serial.print("Reset Pressed ");
  Serial.println(state);
}

void on_stop_press()
{
  state = 10;
  Serial.print("Stop Pressed ");
  Serial.println(state);
}

void initialise_output_pins()
{
  initialise_ultrasonic_pins();
  initialise_coloursensor_pins(); 
}

void initialise_ultrasonic_pins()
{
  // make sure ultrasonic sensors are not emitting at the start
  digitalWrite(pin_ultrasonic_front_trig, LOW); 
  digitalWrite(pin_ultrasonic_side_trig, LOW);
}
void initialise_coloursensor_pins()
{
  digitalWrite(pin_red, LOW);            // make sure color sensor LED is OFF
  digitalWrite(pin_red_block_LED, LOW);  // make sure red block detection LED is OFF
  digitalWrite(pin_blue_block_LED, LOW); // make sure blue block detection LED is OFF
}

void initialise_servo_angles()
{
  set_grab_servo(GRAB_REST_ANGLE);
  set_lift_servo(SERVO_REST_ANGLE);
}


