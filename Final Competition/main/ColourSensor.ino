void activate_color_sensor()
{
  // Turns Red LED ON, waits for 2 sec and then reads comparator output. If HIGH then holding_red_block=true and pickup_block=true

  // To activate color sensor robot must be stationary and perform no other tasks
  holding_red_block = false;
  holding_blue_block = false;
  digitalWrite(pin_red, HIGH); // shine red LED
  delay(2000);                 // for 2 seconds the robot will do nothing, but shine the red LED. INTERUPTS ARE STILL DETECTED THOUGH. If an interupt happens (pin HIGH) then program will jump to void on_red_block_detection
  if (digitalRead(pin_color_red) == HIGH)
  {
    digitalWrite(pin_red, LOW); // switch off sensor LED
    digitalWrite(pin_red_block_LED, HIGH);
    delay(5000); // Specifications say that after block detection, robt must remain still for 5 seconds
    digitalWrite(pin_red_block_LED, LOW);
    holding_red_block = true;
  }
  else
  {
    digitalWrite(pin_red, LOW);
    digitalWrite(pin_blue_block_LED, HIGH);
    delay(5000);
    digitalWrite(pin_blue_block_LED, LOW);
    holding_blue_block = true;
  }
}
