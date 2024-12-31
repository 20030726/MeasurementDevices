//pin define
const int  CLK = 7;
const int  DT = 6;
const int  SW = 5;
int lastCLKstate = HIGH;
int lastDTstate = HIGH;
int lastSWstate = HIGH;
void setup() {
  //baud rate
  Serial.begin(9600);

  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT);
}

//When free the KY-040 CLK=1, DT = 1, SW = 1 (if you test your device is same as this you can use this code)
void loop() {
  int currentCLKstate = digitalRead(CLK);
  int currentDTstate = digitalRead(DT); 
  int currentSWstate = digitalRead(SW);
  //(CW) CLK = 1, DT = 1 -> CLK = 0, DT = 1 -> CLK = 0, DT = 0 -> CLK = 1, DT = 0 -> CLK = 1, DT = 1
  if(currentCLKstate != lastCLKstate && currentCLKstate != currentDTstate && lastCLKstate ==HIGH){
    Serial.println("Clockwise (CW)");
  //(CCW) CLK = 1, DT = 1 -> CLK = 1, DT = 0 -> CLK = 0, DT = 0 -> CLK = 0, DT = 1 -> CLK = 1, DT = 1
  } else if(currentCLKstate != lastCLKstate && currentCLKstate == currentDTstate && lastCLKstate ==HIGH){
      // 逆時針 (CCW)
      Serial.println("Counterclockwise (CCW)");
    }
  if (currentSWstate == LOW && lastSWstate == HIGH) {
  Serial.println("Button Pressed!");
  }

  lastCLKstate = currentCLKstate;
  lastDTstate = currentDTstate;
  lastSWstate = currentSWstate;
}
