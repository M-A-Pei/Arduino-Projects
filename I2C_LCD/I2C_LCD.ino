#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(7,0);
  lcd.print("Hai");
  lcd.setCursor(8,1);
  lcd.print(":D");
}

void loop() {
  delay(1000);
}
