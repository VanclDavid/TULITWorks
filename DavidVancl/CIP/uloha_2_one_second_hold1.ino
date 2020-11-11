#define LED 10
#define LED_RED 11
#define BUTTON 5
unsigned long start,buttonStart;
int ledStuff = 0, buttonStuff = 0, lastStuff = 1, now = 0, redLedStuff = 0;
void setup(){
  pinMode(LED,OUTPUT);
  pinMode(LED_RED,OUTPUT);
  pinMode(BUTTON,INPUT_PULLUP);
  Serial.begin(9600);
}
void loop(){
  switch(redLedStuff){
  	case 0:
    	if(millis() - start >= 1000){
          redLedStuff = 1;
          start = millis();
          digitalWrite(LED_RED, 1);
          Serial.println("REDLED ON");
        }
    	break;
    case 1:
    	if(millis() - start >= 1000){
          redLedStuff = 0;
          start = millis();
          digitalWrite(LED_RED, 0);
          Serial.println("REDLED OFF");
        }
    	break;
  }
  switch(buttonStuff){
  	case 0:
      if((now = digitalRead(BUTTON)) == 1){
        buttonStart = millis();
        lastStuff = 1;
      }
      if(now == 0 && (millis() - buttonStart >= 1000) && lastStuff == 1){
        buttonStuff = 1;
 	  	digitalWrite(LED,1);
        lastStuff = 0;
        Serial.println("BLUELED ON 1s");
      }
    	break;
    case 1:
      if((now = digitalRead(BUTTON)) == 1){
        buttonStart = millis();
        lastStuff = 1;
      }
      if(now == 0 && (millis() - buttonStart >= 1000) && lastStuff == 1){
        buttonStuff = 0;
        digitalWrite(LED,0);
        lastStuff = 0;
        Serial.println("BLUELED OFF 1s");
      }
    	break;
  }
}