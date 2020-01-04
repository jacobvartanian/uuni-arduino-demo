/*
  U@Uni Arduino UNO Demo Code

  This demo code functions as follows:
   - The LEDs blink in a synchronous pattern
   - Each push button is used to control the state of each LED (on or off)
   - The potentiometer controls the rate of blinking

  The circuit:
  - Two LEDs connected to digital pins 9 and 10
  - Two push buttons connected to digital pins 2 and 3
  - A potentiometer connected to analog pin A0

  TASK: Modify the code below such that the LEDs blink in an alternating pattern. Hint: Find the comment flagged as a TODO (to-do)

  There are many ways the code below can be made more efficient. Think about how this could be done and discuss with your peers.

  QUESTION: While the button is held down, the program is paused until the button is released. Why is this the case? Find the section of code that is causing this.

  Author: Jacob Vartanian
  Date: December 2019
*/

// Define which pin is connected to which component. You may need to change this depending on your wiring
#define LED_A_PIN     9
#define LED_B_PIN     10
#define BUTTON_A_PIN  2
#define BUTTON_B_PIN  3
#define DIAL_PIN      A0

#define MIN_BLINK_DELAY 50
#define MAX_BLINK_DELAY 600

// Set up some global variables to store the state of each LED.
int led_a = HIGH;
int led_b = HIGH;

// This will store last time LED was updated
unsigned long previous_millis = 0;

// This will store the current blink state of the LEDs
int blink_state = LOW;

// The code here will run once when the Arduino is powered on or reset
void setup() {
  // Open a connection to the computer. This way we can display values on the screen
  Serial.begin(9600);
  
  // Initialize the LED pins as an output
  pinMode(LED_A_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);

  // Initialise the button pins as an input
  pinMode(BUTTON_A_PIN, INPUT);
  pinMode(BUTTON_B_PIN, INPUT);
}

// The code here will continue to loop forever until the arduino loses power or is rest.
void loop() {
  // If the button is pressed, change the state of the led
  // Remember, because we have a pullup resistor, we need to invert the logic (i.e. 1 is off and 0 is on)
  if (digitalRead(BUTTON_A_PIN) == LOW) {
    // If the LED is off turn it on and vice-versa:
    if (led_a == LOW) {
      led_a = HIGH;
    } else {
      led_a = LOW;
      // Make sure the led is off if it is supposed to be
      digitalWrite(LED_A_PIN, LOW);
    }
    // Delay a short amount of time for debouncing
    delay(10);
    // Wait until the button is released
    while (digitalRead(BUTTON_A_PIN) == LOW)
    {
      // do nothing
    }
  }

  // Do the same for button B
  if (digitalRead(BUTTON_B_PIN) == LOW) {
    // If the LED is off turn it on and vice-versa:
    if (led_b == LOW) {
      led_b = HIGH;
    } else {
      led_b = LOW;
      // Make sure the led is off if it is supposed to be
      digitalWrite(LED_B_PIN, LOW);
    }
    // Delay a short amount of time for debouncing
    delay(10);
    // Wait until the button is released
    while (digitalRead(BUTTON_B_PIN) == LOW)
    {
      // do nothing
    }
  }

  // Store the value of the dial in a local variable called blink_delay
  int dial_position = analogRead(DIAL_PIN);

  // Map the value of blink_delay to be between 100 and 1000 instead of 0 to 1023
  int blink_delay = map(dial_position, 0, 1023, MIN_BLINK_DELAY, MAX_BLINK_DELAY);

  // Get the number of milliseconds that have passed since the Arduino was powered on or reset
  unsigned long current_millis = millis();

  Serial.println(blink_delay);
  // Check to see if it's time to change the blink_state variable, that is, if the difference
  // between the current time and last time we changed the blink_state variable is greater than
  // the interval we want to blink the LED.
  if (current_millis - previous_millis >= blink_delay) {
    // save the last time you blinked the LED
    previous_millis = current_millis;

    // if the LED is off turn it on and vice-versa:
    if (blink_state == LOW) {
      blink_state = HIGH;
    } else {
      blink_state = LOW;
    }
  }

  // Blink the LED if the state of the LED is on
  // TODO: Change the below code so each LED blinks in an alternating pattern
  if (led_a == HIGH) {
    if (blink_state == HIGH) {
      digitalWrite(LED_A_PIN, HIGH);
    }
    else {
      digitalWrite(LED_A_PIN, LOW);
    }
  }
  if (led_b == HIGH) {
    if (blink_state == HIGH) {
      digitalWrite(LED_B_PIN, HIGH);
    }
    else {
      digitalWrite(LED_B_PIN, LOW);
    }
  }
}
