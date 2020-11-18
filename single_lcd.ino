#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int relay[] = {4, 5, 6, 7, 8, 9, 10, 11};
int wet = 550;

void setup() {
  lcd.init();
  lcd.backlight();
  for (int i = 0; i < 8; i++) {
    pinMode(relay[i], OUTPUT);
    digitalWrite(relay[i], HIGH);
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {
    lcd.setCursor(0, 0);
    lcd.print("POT : "); lcd.print(i + 1);
    while (analogRead(i) > wet) {
      lcd.setCursor(0, 1);
      lcd.print("DRY");
      digitalWrite(relay[i], LOW);
    }
    lcd.setCursor(0, 1);
    lcd.print("WET");
    digitalWrite(relay[i], HIGH);
    delay(1000);
  }
}
