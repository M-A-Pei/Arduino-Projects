#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

String namaHari[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  rtc.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  String baris1, baris2;
  lcd.clear();
  DateTime kini = rtc.now();

  baris1 = namaHari[kini.dayOfTheWeek()] + " " + 
           String(kini.day()) + "/" +
           String(kini.month()) + "/" +
           String(kini.year());

  baris2 = String(kini.hour()) + ":" +
           String(kini.minute()) + ":" +
           String(kini.second());
  
  lcd.setCursor(0, 0);
  lcd.print(baris1);
  lcd.setCursor(0, 1);
  lcd.print(baris2);
  delay(1000);
}
