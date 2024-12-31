//    (C.W.)
//  CLK | DT
//    1 |  1 | 3     
//    0 |  1 | 1
//    0 |  0 | 0
//    1 |  0 | 2
//    1 |  1 | 3
//////////////////
//   (C.C.W.)
//  CLK | DT   
//    1 |  1 | 3 
//    1 |  0 | 2
//    0 |  0 | 0  
//    0 |  1 | 1
//    1 |  1 | 3
//////////////////

// Pin definitions
const int CLK = 7;
const int DT = 6;
const int SW = 5;

// Variables to store the state of the rotary encoder and button
int lastCLKstate, lastDTstate, lastSWstate;
int click = 0;

// Debounce configuration
const unsigned long debounceDelay = 5; // Debounce time in milliseconds
unsigned long lastDebounceTime = 0;    // Record the last time an event occurred

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set pin modes
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT);

  // Initialize states
  lastCLKstate = digitalRead(CLK);
  lastDTstate = digitalRead(DT); 
  lastSWstate = digitalRead(SW);
}

void loop() {
    // Read the current states of the rotary encoder and button
    int currentCLKstate = digitalRead(CLK);
    int currentDTstate = digitalRead(DT);
    int currentSWstate = digitalRead(SW);

    // Rotary encoder processing
    if (millis() - lastDebounceTime > debounceDelay) {
        if (currentCLKstate != lastCLKstate && currentCLKstate != currentDTstate && lastCLKstate == HIGH) {
            click += 1;
            Serial.print("Clockwise (CW) and Click: ");
            Serial.println(click);
            lastDebounceTime = millis();
        } else if (currentCLKstate != lastCLKstate && currentCLKstate == currentDTstate && lastCLKstate == HIGH) {
            click -= 1;
            Serial.print("Counterclockwise (CCW) and Click: ");
            Serial.println(click);
            lastDebounceTime = millis();
        }
    }

    // Button press detection
    if (millis() - lastDebounceTime > debounceDelay) {
        if (currentSWstate == LOW && lastSWstate == HIGH) {
            Serial.println("Button Pressed!");
            lastDebounceTime = millis();
        }
    }

    // Update the states
    lastCLKstate = currentCLKstate;
    lastDTstate = currentDTstate;
    lastSWstate = currentSWstate;
}
