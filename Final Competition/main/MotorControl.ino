void set_motors(int left, int right)
{ // function to set both motor speeds and run forwards or backwards
  if (left != last_left_speed)
  {
    myMotorL->setSpeed(abs(left));
    last_left_speed = left;
  }
  if (right != last_right_speed)
  {
    myMotorR->setSpeed(abs(right));
    last_right_speed = right;
  }
  digitalWrite(pin_LED_moving, HIGH); // pin must be HIGH when moving
  if (left < 0)
  {
    myMotorL->run(BACKWARD);
  }
  else
  {
    myMotorL->run(FORWARD);
  }
  if (right < 0)
  {
    myMotorR->run(BACKWARD);
  }
  else
  {
    myMotorR->run(FORWARD);
  }
}

void go_straight()
{
  set_motors(max_speed, max_speed);
  // Serial.println("Go straight");
}

void go_straight_slow()
{
  set_motors(max_speed / 2, max_speed / 2);
}

void reverse_straight()
{
  set_motors(-max_speed, -max_speed);
}

void stop()
{
  set_motors(0, 0);
  // Serial.println("Stopped");
  digitalWrite(pin_LED_moving, LOW);
}

void on_left_junction()
{
  Serial.println("Left Junction");
  go_straight();
  delay(turn_delay);
  set_motors(full_turn_speed, max_speed);
  delay(turn_time);
}

void on_left_deviation()
{
  set_motors(slight_turn_speed, max_speed);
  // Serial.println("Left Deviation");
}

void on_right_deviation()
{
  set_motors(max_speed, slight_turn_speed);
  // Serial.println("Right Deviation");
}

void on_right_junction()
{
  Serial.println("Right Junction");
  go_straight();
  delay(turn_delay);
  set_motors(max_speed, full_turn_speed);
  delay(turn_time);
}

void large_right_deviation()
{
  set_motors(max_speed, large_deviation_speed);
  // Serial.println("large right deviation");
}

void large_left_deviation()
{
  set_motors(large_deviation_speed, max_speed);
  // Serial.println("large left deviation");
}