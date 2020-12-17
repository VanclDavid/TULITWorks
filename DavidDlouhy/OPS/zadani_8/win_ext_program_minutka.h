///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
PROGRAM MINUTKA
---------------
Funguje jako časovač, nastaví se čas a spustí. Po dokonČení odpočtu okno zčervená a vyčká se na vstup od uživatele.
Vstup je detekován a tlaˇ´itku.

IMPLEMENTACE
---------------
Do hlavního programu se přidá funkce startProgram_minutka() s paramery = s pointery.
*p_x      = je xová souŘadnice doteku na display
*p_y      = je yová souŘadnice doteku na display
*button_1 = je tlačíko, ktré slouží k přerušení červené obrazovky
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "mbed.h"
#include "win_ext_display.h"

void minutka_updateTime(int *minute, int *sec, bool count_up);
void startProgram_minutka(uint16_t *p_x, uint16_t *p_y, DigitalIn *button_1);