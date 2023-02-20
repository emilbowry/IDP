#ifndef Timer_h
#define Timer_h
#include "Arduino.h"
unsigned long time;
unsigned long drop_time = 2000;
unsigned long start_time = 0;
unsigned long turn_delay = 100;
unsigned long turn_time = 2000;
unsigned long ramp_time = 25000;
unsigned long no_junctions = 0;
unsigned long time_to_stop = 150000;
unsigned long no_green_line = 0;
unsigned long red_blue_offset = 0;
#endif