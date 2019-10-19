#include <Wire.h>
#include "LiquidCrystal_PCF8574.h"

#define LCD_ADDRESS 0x27
//#define LCD_ADDRESS 0x3F
#define LCD_ROWS 2
#define LCD_COLUMNS 16
#define SCROLL_DELAY 150
#define BACKLIGHT 255

LiquidCrystal_PCF8574 lcd = LiquidCrystal_PCF8574(LCD_ADDRESS);

char buf[80];

int readline(int readch, char *buffer, int len) {
  static int pos = 0;
  int rpos;

  if (readch > 0) {
    switch (readch) {
      case '\r': // Ignore CR
        break;
      case '\n': // Return on new-line
        rpos = pos;
        pos = 0;  // Reset position index ready for next time
        return rpos;
      default:
        if (pos < len - 1) {
          buffer[pos++] = readch;
          buffer[pos] = 0;
        }
    }
  }
  return 0;
}

void setup() {
  Serial.begin(9600);
  lcd.begin(LCD_COLUMNS, LCD_ROWS);
  lcd.setBacklight(BACKLIGHT);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("START");
}

void loop() {
  if (readline(Serial.read(), buf, 17) > 0) {
    lcd.clear();
    lcd.print(buf);
  }

  lcd.scrollDisplayLeft();

  delay(500);

}
