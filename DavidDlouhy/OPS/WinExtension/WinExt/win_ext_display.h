#include "mbed.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include <string>
#define WALLPAPER ((uint32_t)0xFF359AFF)
#define PANEL ((uint32_t)0xBB606060)
#define PANEL_LIGHT ((uint32_t)0xBBBCBCBC)

void initDisplay();
void setBlackScreen();
void displayWinLogo_boot_big();
void setWallpaperScreeen();
uint16_t * touchscreen_getPoss();
void displayWinStartPanel();
void displayWinLogoStartPanel();
void clickWinLogoStartPanel();
void touchscreen_resetPoss(uint16_t *x, uint16_t *y);
void displayWinStartMenuLine(int x, int y, uint32_t color, string textOfLine);
void displayWinStartMenu(string * userName);
void displayLoginPageWelcomw(string * userName);
void closeWinMenu();
void displayWindow();
void displayMinutkaGUI(int *minute, int *sec);
void updateTimeDisplayMinutkaGUI(int *minute, int *sec);
void setRedScreen();
void displayProgramLaunch(uint32_t * color, uint32_t * p_color_text_program, string * programName);