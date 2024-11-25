// C++ code
const int redLedPin = 3;
const int blueLedPin = 5;
const int keyPin = 2;

void setup() 
{
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(keyPin, INPUT_PULLUP);
}

void loop() 
{
  if (digitalRead(keyPin) == LOW) 
  {
    digitalWrite(redLedPin, HIGH);
    delay(500);
    digitalWrite(redLedPin, LOW);
    
    digitalWrite(blueLedPin, HIGH);
    delay(500);
    digitalWrite(blueLedPin, LOW);
  }
}