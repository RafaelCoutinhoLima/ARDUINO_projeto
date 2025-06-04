// PUZZLE DA SENHA
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int button1Pin = 2;
const int button2Pin = 3;
const int button3Pin = 4;
const int buttonClearPin = 5;

String senhaCorreta = "312";
String senhaDigitada = "";

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Digite a senha:");
  
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(buttonClearPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(button1Pin) == LOW) {
    adicionarDigito('1');
    delay(300);
  }

  if (digitalRead(button2Pin) == LOW) {
    adicionarDigito('2');
    delay(300);
  }

  if (digitalRead(button3Pin) == LOW) {
    adicionarDigito('3');
    delay(300);
  }

  if (digitalRead(buttonClearPin) == LOW) {
    apagarSenha();
    delay(300);
  }
}

void adicionarDigito(char digito) {
  if (senhaDigitada.length() < 3) {
    senhaDigitada += digito;
    atualizarDisplay();
  }

  if (senhaDigitada.length() == 3) {
    verificarSenha();
  }
}

void apagarSenha() {
  senhaDigitada = "";
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Digite a senha:");
}

void atualizarDisplay() {
  lcd.setCursor(0, 1);
  lcd.print("Senha: ");
  lcd.print(senhaDigitada);
  lcd.print("   ");
}

void verificarSenha() {
  lcd.setCursor(0, 1);
  if (senhaDigitada == senhaCorreta) {
    lcd.print("Acesso liberado ");
  } else {
    lcd.print("Acesso negado   ");
  }
  delay(2000);
  apagarSenha();
}
