//PUZZLE DAS TEXTURAS E DAS EMOÇÕES
const int ledPin = 7; 
const int buttonPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT); 

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW); 
  } else {
    digitalWrite(ledPin, LOW);
  }
}
