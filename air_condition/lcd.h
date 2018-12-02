#ifndef __LCD_H__
#define __LCD_H__

#include <LiquidCrystal.h>

#define KEYPAD_LEFT       10
#define KEYPAD_RIGHT      20
#define KEYPAD_UP         40
#define KEYPAD_DOWN       80
#define KEYPAD_SELECT     160
#define KEYPAD_RESET      320
#define KEYPAD_UNDEFINED -1

int lcdKeyToKeypad(int lcdKey);

void lcdSetup();

void printToLcd(int row, int column, String str);

void printSelectedKeypad(int lcdKey);

#endif
