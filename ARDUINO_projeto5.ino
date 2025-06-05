//CRONOMETRO + LED DA BOMBA
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <FastLED.h>

#define NUM_LEDS 12         // Número de LEDs na fita
#define DATA_PIN 6          // Pino de dados conectado aos LEDs


LiquidCrystal_I2C lcd(0x27, 16, 2);


const int botaoStartPause = 2;
const int botaoZerar = 3;


bool rodando = false;
bool estadoAnteriorStart = HIGH;
bool estadoAnteriorZerar = HIGH;

unsigned long tempoAnterior = 0;
int segundos = 0;
int minutos = 0;

CRGB leds[NUM_LEDS]; 

unsigned long tempoBlink = 0;
bool ledsLigados = false;
const unsigned long intervaloBlink = 500; 

void setup() {
  pinMode(botaoStartPause, INPUT_PULLUP);
  pinMode(botaoZerar, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);

  lcd.setCursor(0, 0);
  lcd.print("Cronometro:");
  lcd.setCursor(0, 1);
  lcd.print("Pausado       ");
}

void loop() {
  bool estadoBotaoStart = digitalRead(botaoStartPause);
  bool estadoBotaoZerar = digitalRead(botaoZerar);

  if (estadoBotaoStart == LOW && estadoAnteriorStart == HIGH) {
    delay(50);
    rodando = !rodando;

    lcd.setCursor(0, 1);
    if (rodando) {
      lcd.print("Tempo: ");
      mostrarTempo();
    } else {
      lcd.print("Pausado       ");
    }
  }
  estadoAnteriorStart = estadoBotaoStart;

  if (estadoBotaoZerar == LOW && estadoAnteriorZerar == HIGH) {
    delay(50);
    if (!rodando) {
      segundos = 0;
      minutos = 0;
      lcd.setCursor(0, 1);
      lcd.print("Pausado       ");
    }
  }
  estadoAnteriorZerar = estadoBotaoZerar;

  if (rodando && (millis() - tempoAnterior >= 1000)) {
    tempoAnterior = millis();
    segundos++;

    if (segundos >= 60) {
      segundos = 0;
      minutos++;
    }

    lcd.setCursor(0, 1);
    lcd.print("Tempo: ");
    mostrarTempo();
  }

  if (!rodando) {
    efeitoBlink();
  } else {
   
    acendeLedVerde();
  }
}

void mostrarTempo() {
  if (minutos < 10) lcd.print("0");
  lcd.print(minutos);
  lcd.print(":");
  if (segundos < 10) lcd.print("0");
  lcd.print(segundos);
  lcd.print("   ");
}

void acendeLedVerde() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
  }
  FastLED.show();
}

void acendeLedVermelho() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
  }
  FastLED.show();
}

void efeitoBlink() {
  if (millis() - tempoBlink >= intervaloBlink) {
    tempoBlink = millis();

    if (ledsLigados) {
      for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Black;
      }
    } else {
      for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Green;
      }
    }

    ledsLigados = !ledsLigados; 
    FastLED.show();
  }
}
