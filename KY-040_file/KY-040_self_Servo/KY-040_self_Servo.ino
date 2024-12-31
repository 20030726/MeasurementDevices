#include <Servo.h>

// Pin definitions
const int CLK = 7;
const int DT = 6;
const int SW = 5;
//Operating speed: 0.1sec /60degree(4.8v) 
const int degperlick = 10;
// Variables to track the state of the rotary encoder and button
int lastCLKstate, lastDTstate, lastSWstate;
int click = 0;
Servo myServo;

// Debounce-related variables
const unsigned long debounceDelay = 5; // Debounce delay time in milliseconds
unsigned long lastDebounceTime = 0;

void setup() {
  // Attach the servo to pin 9
  myServo.attach(9);

  // Initialize serial communication
  Serial.begin(115200);

  // Set pin modes
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT);

  // Initialize the last state of the rotary encoder and button
  lastCLKstate = digitalRead(CLK);
  lastDTstate = digitalRead(DT); 
  lastSWstate = digitalRead(SW);
}

void loop() {
  // Read the current states of the rotary encoder and button
  int currentCLKstate = digitalRead(CLK);
  int currentDTstate = digitalRead(DT);
  int currentSWstate = digitalRead(SW);

  // Handle rotary encoder rotation
  if (currentCLKstate != lastCLKstate) {
    if (currentCLKstate != currentDTstate && lastCLKstate == HIGH) {
      click += 1;
      Serial.print("Clockwise (CW) and Click: ");
    } else if (currentCLKstate == currentDTstate && lastCLKstate == HIGH) {
      click -= 1;
      Serial.print("Counterclockwise (CCW) and Click: ");
    }
  click = constrain(click, 0, 180/degperlick);
  Serial.println(click);
  }
  // Handle button press detection
  if (currentSWstate == LOW && lastSWstate == HIGH) {
    click = 90/degperlick; // Reset click value
    Serial.println("Button Pressed! Reset Click to 90 (Angle 90)");
  }

  // Control the servo motor (20 clicks per revolution)
  int angle = click*degperlick; // Ensure angle stays within 0~180
  Serial.print("Current Servo Angle: ");
  Serial.println(angle);
  myServo.write(angle); // Move the servo to the calculated angle

  // Update the last states
  lastCLKstate = currentCLKstate;
  lastSWstate = currentSWstate;
}
