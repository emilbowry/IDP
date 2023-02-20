void read_ultrasonic_front()
{
  // Clears the trigPin
  digitalWrite(pin_ultrasonic_front_trig, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(pin_ultrasonic_front_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_ultrasonic_front_trig, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(pin_ultrasonic_front_echo, HIGH);
  // Calculating the distance
  distance_front = duration * 0.034 / 2; // in cm
}

void read_ultrasonic_side()
{
  digitalWrite(pin_ultrasonic_side_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(pin_ultrasonic_side_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_ultrasonic_side_trig, LOW);
  long duration = pulseIn(pin_ultrasonic_side_echo, HIGH);
  distance_side = duration * 0.034 / 2;
}