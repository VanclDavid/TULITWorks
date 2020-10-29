#define LED 10
#define LED_RED 11
#define BUTTON 5
unsigned long start,buttonStart;
int ledStuff = 0, buttonStuff = 0, lastStuff = 1, now = 0, redLedStuff = 0;
void setup(){
  pinMode(LED,OUTPUT);
  pinMode(LED_RED,OUTPUT);
  pinMode(BUTTON,INPUT_PULLUP);
}
void buttonAction(void (*innerFunction)()){
  if((now = digitalRead(BUTTON)) == 1){
  	buttonStart = millis();
    lastStuff = 1;
  }
  if(now == 0 && (millis() - buttonStart >= 1000) && lastStuff == 1){
    (*innerFunction)();
    lastStuff = 0;
  }
}
void ledAction(int type){
  digitalWrite(LED_RED, type);
  if(millis() - start >= 1000){
    redLedStuff = type;
    start = millis();
  }
}
void loop(){
  switch(redLedStuff){
  	case 0:
    	ledAction(1);
    	break;
    case 1:
    	ledAction(0);
    	break;
  }
  switch(buttonStuff){
  	case 0:
    buttonAction([](void){buttonStuff = 1;
 	  digitalWrite(LED,1);
    });
    	break;
    case 1:
    buttonAction([](void){buttonStuff = 0;
      digitalWrite(LED,0);
    });
    	break;
  }
}