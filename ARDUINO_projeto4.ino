//PUZZLE DO POTENCIOMETRO
const int pinoPotenciometro = A0;

const int led1 = 6;
const int led2 = 9;  
const int led3 = 10;
const int led4 = 11; 
const int ledExtra = 2; 

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(ledExtra, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int valorPot = analogRead(pinoPotenciometro);

  Serial.print("Valor do potenciômetro: ");
  Serial.println(valorPot);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(ledExtra, LOW);

  if (valorPot <= 255) {
    digitalWrite(led1, HIGH);
  } else if (valorPot <= 511) {
    digitalWrite(led2, HIGH);
  } else if (valorPot <= 767) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led4, HIGH);
    digitalWrite(ledExtra, HIGH);
  }

  delay(100);
}
