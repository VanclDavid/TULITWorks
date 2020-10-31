//RFID IRQ=pin5    ->   Not used. Leave open
//RFID MISO=pin4   ->   Nucleo SPI_MISO=PA_6=D12
//RFID MOSI=pin3   ->   Nucleo SPI_MOSI=PA_7=D11
//RFID SCK=pin2    ->   Nucleo SPI_SCK =PA_5=D13
//RFID SDA=pin1    ->   Nucleo SPI_CS  =PB_6=D10
//RFID RST=pin7    ->   Nucleo         =PA_9=D8
//3.3V and Gnd to the respective pins
                              
#include "mbed.h"
#include "MFRC522.h"
#include "LCDLibrary.h"

#define MF_RESET    D8
DigitalOut LedGreen(LED1);
Serial pc(SERIAL_TX, SERIAL_RX);

MFRC522    RfChip   (SPI_MOSI, SPI_MISO, SPI_SCK, SPI_CS, MF_RESET);

int main(void) {
  pc.printf("starting...\n");
  RfChip.PCD_Init();
  initLCD();

  while (true) {
    preparePrintLCD(LCD_COLOR_LIGHTGREEN,&LCD_DEFAULT_FONT,LCD_COLOR_LIGHTGREEN,LCD_COLOR_BLACK);
    printOnLineLCD(3, (uint8_t *) "LISTENING", CENTER_MODE);

    if ( ! RfChip.PICC_IsNewCardPresent()){
      wait_ms(500);
      continue;
    }

    if ( ! RfChip.PICC_ReadCardSerial()) {
      wait_ms(500);
      continue;
    }

    uint8_t accessData[] = {0x10,0x28,0x89,0x7C};

    bool accessed = true;
    pc.printf("Card accessing UID: ");
    for (uint8_t i = 0; i < RfChip.uid.size; i++){
      if(RfChip.uid.uidByte[i] != accessData[i]) accessed = false;
      pc.printf(" %X02 ", RfChip.uid.uidByte[i]);
    }

    pc.printf("\n");

    uint8_t piccType = RfChip.PICC_GetType(RfChip.uid.sak);
    pc.printf("PICC Type: %s \n\r", RfChip.PICC_GetTypeName(piccType));

    if(accessed){
        preparePrintLCD(LCD_COLOR_GREEN,&LCD_DEFAULT_FONT,LCD_COLOR_GREEN,LCD_COLOR_BLACK);
        printOnLineLCD(2, (uint8_t *) RfChip.PICC_GetTypeName(piccType), CENTER_MODE);
        printOnLineLCD(3, (uint8_t *) "Status: ACCESS", CENTER_MODE);
        pc.printf("ACCESS");
    } else {
        preparePrintLCD(LCD_COLOR_RED,&LCD_DEFAULT_FONT,LCD_COLOR_RED,LCD_COLOR_BLACK);
        printOnLineLCD(2, (uint8_t *) RfChip.PICC_GetTypeName(piccType), CENTER_MODE);
        printOnLineLCD(3, (uint8_t *) "Status: DENIED", CENTER_MODE);
        pc.printf("DENIED");
    }
    wait_ms(2000);
    preparePrintLCD(LCD_COLOR_ORANGE,&LCD_DEFAULT_FONT,LCD_COLOR_ORANGE,LCD_COLOR_BLACK);
    printOnLineLCD(3, (uint8_t *) "LOCKED", CENTER_MODE);
    wait_ms(4000);
  }
}