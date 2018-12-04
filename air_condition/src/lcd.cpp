#include "lcd.h"
#include "wemos_d1.h"

LiquidCrystal lcd(D8, D9, D4, D5, D6, D7);

void lcdSetup() {
  lcd.begin(16, 2);

  // Print a message to the LCD.
  lcd.print("LCD Key Shield Init!");
}

int lcdKeyToKeypad(int lcdKey) {
  int result = -1;

  if (lcdKey < 100) {
    result = KEYPAD_RIGHT;
  }
  else if (lcdKey < 200) {
    result = KEYPAD_UNDEFINED;
  }
  else if (lcdKey < 400) {
    result = KEYPAD_UP;
  }
  else if (lcdKey < 600) {
    result = KEYPAD_DOWN;
  }
  else if (lcdKey < 800) {
    result = KEYPAD_LEFT;
  }

  return result;
}

void printToLcd(int row, int column, String str) {
  clearLine(row);

  lcd.setCursor(column, row);
  lcd.print(str);
}

void clearLine(int row) {
  lcd.setCursor(0, row);
  lcd.print("                ");
}

void printSelectedKeypad(int lcdKey) {
  switch (lcdKeyToKeypad(lcdKey)) {
    case KEYPAD_RIGHT:
      printToLcd(1, 0, "Right");
      break;

    case KEYPAD_LEFT:
      printToLcd(1, 0, "Left ");
      break;

    case KEYPAD_UP:
      printToLcd(1, 0, "Up   ");
      break;

    case KEYPAD_DOWN:
      printToLcd(1, 0, "Down ");
      break;
  }
}
