void setup() {
    Serial.begin(9600);
}

int buttonStatus = 0;
void loop() {
  int pinValue = digitalRead(2);
  delay(10); // quick and dirty debounce filter
  if (buttonStatus != pinValue) {
    buttonStatus = pinValue;
    Serial.println(buttonStatus);
  }
}
