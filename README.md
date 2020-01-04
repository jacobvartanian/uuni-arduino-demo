# Introduction to Electronics

Download the tutorial slides at: tiny.cc/uuni-arduino

## Task 1

**Date and Time:** Monday 13th January 2020, 2:20pm – 3:30pm

**Weighting:** 25%

**CAPRI Learning Objective:** I4: Innovation and Creativity (implementing ideas)

### Task Description:

Part 1: Construct a working prototype of an electronic circuit with the following inputs/outputs:
1. An LED which can be controlled by the Arduino on digital pin 9
2. A push button which can be used to control the Arduino on digital pin 2
3. A potentiometer (variable resistor) which can be used to control the Arduino on analog pin A0

![Breadboard](Breadboard&#32;Prototype_bb.png)

![Schematic](Breadboard&#32;Prototype_schem.png)

Part 2:
1. Download the source code and upload it to the Arduino
2. Verify that your circuit works as expected:
   - The LED is blinking at a constant rate
   - The push button turns on and off the LED
   - The potentiometer controls the rate of blinking

Part 3:
1. Modify the above circuit so there are 2 LEDs and 2 push buttons
2. Modify the source code to add additional functionality to these new components. Refer to the comments within the code for steps on how to do this. The circuit should function as follows:
   - The LEDs blink in an **alternating pattern**
   - Each push button is used to control the state of each LED (on or off)
   - The potentiometer controls the rate of blinking

Discussion:
1. There are many ways the code below can be made more efficient. Think about how this could be done and discuss with your peers.
2. While the button is held down, the program is paused until the button is released. Why is this the case? Find the section of code that is causing this.

### Marking Criteria Checklist:

| Description | Marks |
| :- | -: |
| Source code successfully uploaded to the Arduino  | /2 |
| LED blinks at constant rate  | /1 |
| Push button turns on and off LED | /1 |
| Potentiometer controls rate of blinking | /1 |
| Additional LED connected | /1 |
| Additional push button connected | /1 |
| Source code is modified and uploaded such that the circuit functions as described in part 3 | /3 |
| TOTAL | /10 |