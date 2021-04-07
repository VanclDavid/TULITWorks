#pragma once
#include "mbed.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"

void initLCD ();
void preparePrintLCD(uint32_t backgroundColor,sFONT *font,uint32_t backgroundTextColor,uint32_t foregroundColor);
void pauseLCD(int delay);
void clearLineLCD(int lineNumber);
void printOnLineLCD(int lineNumber,uint8_t * text, Text_AlignModeTypdef mode);
void pauseLCDWithThread(int delay);
void printLCDError();
uint8_t getLCDStatus();