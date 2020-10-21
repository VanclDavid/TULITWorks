/*
  This program blinks pin 13 of the Arduino (the
  built-in LED)
*/
#define LED1 13
#define LED2 8
#define TLAC 2

bool tl;
unsigned long start;
int stav_led = 0;
int stav_t1 = 0;
int push_button=0;
bool was_pushed=false;
void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(TLAC, INPUT_PULLUP);
  start=millis();
}
bool next(){
  if(millis()-start>=1000){start=millis();return true;}
  return false;
}
bool button_press(){
	if(digitalRead(TLAC)==0){ 
      if(!was_pushed){
        if(push_button==3){push_button=0;return true;} 
        else {
				push_button++;
        	}
        was_pushed=true;
      }
    } else {
      	was_pushed=false;
    }
  return false;
}
void loop()
{
  switch(stav_led){
  	case 0:
    if(next()){stav_led=1;digitalWrite(LED1, 1);}
    break;
    case 1:
    if(next()){stav_led=0;digitalWrite(LED1, 0);}
    break;
  }
  switch(stav_t1){
  	case 0:
    if(button_press()){stav_t1=1;digitalWrite(LED2, 1);}
    break;
    
    case 1:
	 if(button_press()){stav_t1=0;digitalWrite(LED2, 0);}
    break;
  }
}