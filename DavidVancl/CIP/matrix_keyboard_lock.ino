#define PINS_START    2
#define LAST_ROW_PIN  5
#define PINS_END      9
#define RED_LED       13
#define GREEN_LED     12
char buttons_text[4][4] = {{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};
char last_type = '%';
bool was_clicked = false,_input = false;
int green_led_stuff = 0,start_green = 0,pause_reset = 0,input_index = 0,lock_stuff = 0;
int green_led_res = 0,red_led_res = 0;
char combination[4] = {'1','2','3','4'},input[4] = {'\0','\0','\0','\0'};

void setup(){
  for(int i = PINS_START; i <= PINS_END;i++){
    if (i <= LAST_ROW_PIN) pinMode(i,INPUT_PULLUP);
    else pinMode(i,OUTPUT);
  }
  pinMode(GREEN_LED,OUTPUT);
  pinMode(RED_LED,OUTPUT);
  Serial.begin(9600);
  start_green = millis();
}

void loop(){
  was_clicked = false;
  _input = false;
  for(int i = (LAST_ROW_PIN + 1); i <= PINS_END;i++){
    digitalWrite(i,0);
    for(int j = PINS_START; j <= LAST_ROW_PIN; j++){
      	if(digitalRead(j) == 0){
          was_clicked = true;
          if(last_type != buttons_text[j-2][i-6]){
            Serial.println(buttons_text[j-2][i-6]);
            last_type = buttons_text[j-2][i-6];
            _input = true;
          }
        }
    }
    digitalWrite(i,1);
  }
  if (was_clicked == false) last_type = '%';
  
  switch(lock_stuff){
  	case 0:
      if(millis() - start_green >= 500){
        green_led_stuff = !green_led_stuff;
        start_green = millis();
        digitalWrite(GREEN_LED, green_led_stuff);
      }
      if(_input){
		lock_stuff = 1;
        green_led_stuff = 0;
        digitalWrite(GREEN_LED, green_led_stuff);
        pause_reset = millis();
        input[input_index] = last_type;
        input_index++;
      }
    	break;
    case 1:
      if(_input){
        pause_reset = millis();
        input[input_index] = last_type;
        input_index++;
        if(input_index == 4){
        	if(input[0] == combination[0] &&
              	input[1] == combination[1] &&
              	input[2] == combination[2] &&
              	input[3] == combination[3]){
              	green_led_res = millis();
              	lock_stuff = 2;
            } else {
              	red_led_res = millis();
            	lock_stuff = 3;
            }
        }
      }
      if(millis() - pause_reset >= 1000){
       	lock_stuff = 4;
      }
    	break;
    case 2:
    	digitalWrite(GREEN_LED,1);
      	if(millis() - green_led_res >= 1000){
          digitalWrite(GREEN_LED,0);
          lock_stuff = 4;
        }
    	break;
    case 3:
    	digitalWrite(RED_LED,1);
    	if(millis() - red_led_res >= 1000){
          digitalWrite(RED_LED,0);
          lock_stuff = 4;
        }
    	break;
    case 4:
    	start_green = millis();
    	input[0] = '\0';
        input[1] = '\0';
        input[2] = '\0';
        input[3] = '\0';
    	lock_stuff = 0;
    	input_index = 0;
    	break;
  }
}

//V zadání je že "Pokud stiskne nesprávné tlačítko" je reset. 
//Trošičku jsem si to upravil aby nebylo možné kod jednoduše zjistit,
//tak ho to nechá zadat 4 místný kod a pak až řekne jestli true nebo false. (Navyšuje počet možných kombinací)
//
//V konkretním případě pro zadání by stav 1 vypadal zhruba takto:
//case 1:
//      if(_input){
//        pause_reset = millis();
//        if(combination[input_index] != last_type){
//	  lock_stuff = 3;
//	} else {
//	  input[input_index] = last_type;
//	}
//	input_index++;
//	if(input_index == 4){
//        	if(input[0] == combination[0] &&
//              	input[1] == combination[1] &&
//              	input[2] == combination[2] &&
//              	input[3] == combination[3]){
//              	green_led_res = millis();
//              	lock_stuff = 2;
//            }
//	}
//      }
//      if(millis() - pause_reset >= 1000){
//       	lock_stuff = 4;
//      }
//    	break;