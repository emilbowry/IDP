void start_state()
{
  // Reset values
  red_blue_offset = 0;
  set_lift_servo(SERVO_REST_ANGLE); // Start with lifted mechanism
  set_grab_servo(GRAB_REST_ANGLE);
  delay(500);
  follow_line();
  delay(1000);
  state = 1;
}

void box_start_state();()
{
  if (line_sensor_state[3])
  {
    on_right_junction();
    state = 2;
  }
}
void line_following_state()
{
  start_time = time;
  time = millis() - start_time;
  on_branch = false;
  through_tunnel = false;
  junction_counter = 0;
  holding_red_block = false;
  holding_blue_block = false;
  past_blue_box = false;
  no_junctions = 0;
  block_junction_counter = 0;
  follow_line_timer(ramp_time + red_blue_offset);
  Serial.println("state 3");
  state = 3;
}
void pickup_block_state()
{
  if (block_counter > 0)
  {
    set_lift_servo(50);
    state = 21;
  }
  else
  {
    if (scan_and_lift_block())
    {
      block_counter++;
      state = 4;
    }
    else
    {
      follow_line();
    }
  }
}
void reverse_branch_state()
{
  if (on_branch)
  {
    reverse_straight();
    if (line_sensor_state[3] && line_sensor_state[0])
    {
      on_right_junction();
      state = 5;
    }
  }
  else
  {
    state = 5;
  }
}
void tunnel_state()
{
  read_ultrasonic_side();
  if (distance_side < 25)
  {
    tunnel();
    through_tunnel = true;
  }
  else if (through_tunnel && (line_sensor_state[1] || line_sensor_state[2]))
  {
    follow_line_timer(10000);
    state = 6;
  }
  else
  {
    follow_line();
  }
}
void go_truck_area_state()
{
  if (line_sensor_state[3])
  {
    Serial.println("Line found");
    delay(50);
    if (time > no_junctions)
    {
      junction_counter++;
      Serial.println(junction_counter);
      no_junctions = time + 1000;
    }
  }

  if (holding_blue_block && junction_counter == 1)
  {
    on_right_junction();
    state = 7;
  }
  else if (holding_red_block && junction_counter == 3)
  {
    on_right_junction();
    state = 7;
  }
  else
  {
    follow_line();
  }
}
void drop_block_state()
{
  read_ultrasonic_front();
  if (distance_front <= drop_distance)
  {
    drop_counter++;
    if (drop_counter > 3)
    {
      stop();
      set_lift_servo(0);
      go_straight();
      delay(2300);
      stop();
      set_lift_servo(10);
      delay(200);
      set_grab_servo(GRAB_REST_ANGLE);
      delay(200);
      reverse_straight();
      delay(3500);
      Serial.println("returning to line");
      state = 8;
    }
  }
  else
  {
    follow_line_slow();
  }
}
void return_line_state()
{
  if (holding_red_block && (line_sensor_state[3] || line_sensor_state[0]))
  {
    if (millis() < time_to_stop && block_counter <= 1)
    {
      stop();
      set_lift_servo(SERVO_REST_ANGLE);
      set_grab_servo(GRAB_REST_ANGLE);
      delay(500);
      on_left_junction();
      red_blue_offset = -8000;
      state = 2;
    }
    else
    {
      stop();
      on_right_junction();
      follow_line_timer(5000);
      state = 9;
    }
  }

  else if (holding_blue_block && line_sensor_state[0])
  {
    stop();
    on_left_junction();
    if (millis() < time_to_stop && block_counter <= 1)
    {
      stop();
      set_lift_servo(SERVO_REST_ANGLE);
      set_grab_servo(GRAB_REST_ANGLE);
      delay(500);
      red_blue_offset = 15000;
      state = 2;
    }
    else
    {
      follow_line_timer(5000);
      state = 9;
    }
  }

  else
  {
    reverse_straight();
  }
}
void return_to_start_state()
{
  if (holding_red_block && line_sensor_state[0])
  {
    stop();
    set_lift_servo(0);
    delay(500);
    on_left_junction();
    follow_line_timer(8000);
    state = 10;
  }
  else if (holding_blue_block && line_sensor_state[3])
  {
    stop();
    set_lift_servo(0);
    delay(500);
    on_right_junction();
    follow_line_timer(8000);
    state = 10;
  }
  else
  {
    follow_line();
  }
}
void stop_state()
{
  stop();
}
void side_detection_state()
{
  read_ultrasonic_side();
  if (distance_side <= 15)
  {
    stop();
    while (!line_sensor_state[0])
    {
      follow_line();
      read_all_line_sensors();
    }
    go_straight();
    delay(200);
    stop();
    set_lift_servo(SERVO_REST_ANGLE);
    on_left_junction();
    Serial.println("Turned Left");
    stop();
    while (!scan_and_lift_block())
    {
      follow_line_slow();
      read_all_line_sensors();
    }
    Serial.println("Block lifted");
    on_branch = true;
    block_counter++;
    state = 4;
  }
  else if (line_sensor_state[0])
  {
    if (time > no_junctions)
    {
      no_junctions = time + 1000;
      set_lift_servo(SERVO_REST_ANGLE);
      delay(200);
      if (block_junction_counter > 1)
      {
        Serial.println("4");
        state = 4;
      }
      else
      {
        Serial.println("Entering state22 from 21");
        state = 22;
        block_junction_counter++;
      }
    }
  }
  else
  {
    follow_line();
  }
}

void side_block_pickup()
{
  if (scan_and_lift_block())
  {
    block_counter++;
    state = 4;
  }
  else if (line_sensor_state[0])
  {
    if (time > no_junctions)
    {
      no_junctions = time + 1000;
      set_lift_servo(45);
      set_lift_servo(50);
      Serial.println("Entering State21 from 22");
      block_junction_counter++;
      state = 21;
    }
  }
  else
  {
    follow_line();
  }
}

void ultrasonic_test_state()
{
  read_ultrasonic_front();
  Serial.println(distance_front);
  delay(100);
}
void line_reader_test_state()
{
  Serial.print(line_sensor_state[0]);
  Serial.print(line_sensor_state[1]);
  Serial.print(line_sensor_state[2]);
  Serial.println(line_sensor_state[3]);
  delay(100);
}

void follow_line_test(){
  follow_line();
}