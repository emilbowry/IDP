#ifndef StateController_h
#define StateController_h

// State parameters
bool holding_red_block = false;
bool holding_blue_block = false;
bool on_branch = false;
bool through_tunnel = false;
bool past_blue_box = false;
double distance_front;
double distance_side;
double colour_sense_distance = 15;
int block_counter = 0;
double tunnel_offset = 11.5;
int junction_counter = 0;
int block_junction_counter = 0;

int state = 10; // Begin in stopped state until button is pressed
#endif