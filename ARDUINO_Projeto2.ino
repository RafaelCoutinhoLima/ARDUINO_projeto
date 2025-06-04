//PUZZLE PEGA MARMOTAS 
const int yellowLEDs[4] = {2, 9, 8, 10};


const int buttons[4] = {5, 4, 3, 11};


const int greenLEDPin = 7;

int currentLED = -1;
int acertosSeguidos = 0;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(yellowLEDs[i], OUTPUT);
    pinMode(buttons[i], INPUT_PULLUP);
  }

  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(greenLEDPin, OUTPUT); 
  digitalWrite(greenLEDPin, LOW);

  randomSeed(analogRead(A0));
}

void loop() {
  if (acertosSeguidos >= 10) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(greenLEDPin, HIGH);
      delay(500);
      digitalWrite(greenLEDPin, LOW);
      delay(500);
    }

    acertosSeguidos = 0;
    currentLED = -1;
    return;
  }
  currentLED = random(0, 4);
  digitalWrite(yellowLEDs[currentLED], HIGH);

  bool respostaRecebida = false;
  while (!respostaRecebida) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(buttons[i]) == LOW) {
        respostaRecebida = true;
        delay(50);

        if (i == currentLED) {

          digitalWrite(12, HIGH);
          digitalWrite(greenLEDPin, HIGH);
          delay(500);
          digitalWrite(12, LOW);
          digitalWrite(greenLEDPin, LOW);
          acertosSeguidos++;
        } else {

          digitalWrite(13, HIGH);
          delay(500);
          digitalWrite(13, LOW);
          acertosSeguidos = 0;
        }
        break;
      }
    }
  }

  digitalWrite(yellowLEDs[currentLED], LOW);
  delay(400); // mesmo delay para todos os LEDs
}
