bool read_line_sensor(byte pin)
{
  if (analogRead(pin) > 800)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void read_all_line_sensors()
{
  line_sensor_state[0] = read_line_sensor(pin_left_line_sensor);
  line_sensor_state[1] = read_line_sensor(pin_middle_left_line_sensor);
  line_sensor_state[2] = read_line_sensor(pin_middle_right_line_sensor);
  line_sensor_state[3] = read_line_sensor(pin_right_line_sensor);
}

void follow_line()
{
  if (line_sensor_state[0])
  {
    large_left_deviation();
    return;
  }
  else if (line_sensor_state[3])
  {
    large_right_deviation();
    return;
  }

  if (line_sensor_state[1])
  {
    on_left_deviation();
    return;
  }
  else if (line_sensor_state[2])
  {
    on_right_deviation();
    return;
  }
  go_straight();
}

void follow_line_timer(unsigned long duration)
{
  unsigned long end_time = time + duration;
  while (time < end_time)
  {
    follow_line();
    read_all_line_sensors();
    time = millis() - start_time;
  }
  Serial.println("Line Follow Elapsed");
}

void follow_line_slow()
{
  if (line_sensor_state[0])
  {
    set_motors(large_deviation_speed / 2, max_speed / 2);
    return;
  }
  else if (line_sensor_state[3])
  {
    set_motors(max_speed / 2, large_deviation_speed / 2);
    return;
  }
  else if (line_sensor_state[1])
  {
    set_motors(slight_turn_speed / 2, max_speed / 2);
    return;
  }
  else if (line_sensor_state[2])
  {
    set_motors(max_speed / 2, slight_turn_speed / 2);
    return;
  }
  go_straight_slow();
}

void tunnel()
{
  double error = distance_side - tunnel_offset; // keep constant distance from tunnel wall
  if (error > 0.5)
  {
    on_left_deviation();
  }
  else if (error < -0.5)
  {
    on_right_deviation();
  }
  else
  {
    go_straight();
  }
}