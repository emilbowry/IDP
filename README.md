# IDP

## Overall System Design

The overall structure of the software implementation included a state machine for each stage in the robot’s course which made the code much more modular and allowed easier debugging since individual states were able to be tested. Various algorithms were required for each state:

## State machine overview:

### 1) Initialisation
When the device is powered on or reset, the servos are lifted to their rest angles and the robot goes straight past the start box. The line sensors are then read and the motor speeds are set to turn 90 degrees once the first junction is detected.

### 2) Line Following

For the line following, proportional control is used for the two inner line sensors which correct small deviations and the outer line sensors correct large deviations which allows a large margin for error.

The initial line following ramp state uses built-in millis function to time and identify when the ramp has been traversed before activating the pick-up state. All variables are also reset as necessary in this state in order to return to this state when picking up a second block.

### 3) Detecting block and handling

Both front and side ultrasonic sensors are activated in this state. If the block counter is greater than 0, the side ultrasonic is read once a branch is detected by the far left line sensor and the robot turns 90 degrees to the left. A boolean that identifies that it is on a branch is set to true.

In this state the robot continues following the line until the front ultrasonic detects a block 15 cm away before line following slowly until it is 8 cm away and stopping. A servo is then used to drop the lift arm which contains the colour sensing circuitry and close the grabber with another servo. This colour sensor is then activated which turns on a red LED and reads from the digital pin connected to the colour detection circuit which will be high if a red block is detected. The relevant LED is then set to high for 5 seconds while the robot is stationary.

Once the colour has been detected, the arm is then lifted and the robot reverses and turns 90 degrees upon detection of the line if it is on a branch. The block counter is incremented and line following then continues.

### 4) Drop off and return to start

In the tunnel state, the side ultrasonic sensor is continually read until the tunnel walls are detected within 25 cm. Proportional control is then used to maintain a set distance of 11.5cm from the tunnel wall, using the same turn speeds as with line following. Upon first detection of the tunnel a boolean is set to true and once any of the line sensors detect the line while this is true then the next state is activated.

During the drop off state, Line following continues and junctions are counted depending on the colour of the block. A timeout is used so that the junction counter is only incremented once at each junction. 

Once the correct number of junctions is reached the robot will turn 90 degrees and raise the servo arm to drop the block on the truck after detecting it is a certain distance from it with the front ultrasonic sensor. In order to consistently drop the block on the truck, slow line following is used to reach the truck area before activating a predefined drop off sequence which even allowed it to stack blocks on top of each other on the truck.

The robot then reverses from the truck area and either returns to the initial ramp state, if there is sufficient time remaining and the block counter is less than 2, or returns to the start box by detecting the start box junction.

## Testing

### Use of serial communication

Decided to use strings read from serial to adjust variables such as turn speeds and hard coding 90 degree turns during runtime which allowed much more efficient testing. Using this method was 80% faster than uploading over USB.


### WiFi

In addition, an AP server was set up over WiFi which allowed different points in the state machine to be activated quickly so that each state could be tested individually before running all states in sequence. This proved to be very effective because the exact location of issues within the code could be identified quickly and made integration of different mechanisms much easier.

### Prototyping

Initially, line following was identified as the main software challenge so within the first few days the software team developed a working line following algorithm on a cardboard prototype. This allowed the navigation to be much more polished by the time of the final competition which allowed the team to have confidence in achieving at least the points gained from following the line around the track.


## Major Decisicions

### 1) Use of Proportional Control as opposed to PID 

Decided against using PID control since the line following algorithm would have required much more tuning to adjust Kp and Ki variables with analogue line sensors. This was decided upon testing with binary line sensor circuitry which worked very reliably.

### 2) Use of timing to exit ramp state
Decided against counting junctions since it introduced a greater possibility of error due to the robot deviating from the line significantly when climbing the ramp sometimes which would have been identified as a junction to enter the detect block state. Therefore, a global time variable was used to reflect the time since line following begins.

# Competition Outcome

Unfortunately, we ended up coming in second place both in our competition and in the entire Cambridge Engineering cohort, which was quite disappointing. Despite having flawlessly completed 20 practice runs, our Ultrasonic Sensor (US) malfunctioned during the actual competition.

The sensor detected an abnormal reading of an object 150mm away, even though there was nothing there. One possible cause could be attributed to me turning on our sound system to play the Imperial March from Star Wars. It's possible that when the speaker was initialized, it caused an ultrasonic emission at the start due to a sudden change in voltage, such as a delta-like pulse from turning it on. I will need to examine the specifications of the speaker and review our US code in order to determine the root cause of the malfunction.
