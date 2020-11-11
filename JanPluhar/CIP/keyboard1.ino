int last_pressed_key;
void setup()
{
    Serial.begin(9600);
    for(int i=2;i<6;i++){pinMode(i, INPUT_PULLUP);} //rows
  	for(int i=6;i<10;i++){pinMode(i, OUTPUT);digitalWrite(i, 1);} //columns
	last_pressed_key=-1;
}
char chars[4][4]={{'1','2','3','A'},
				  {'4','5','6','B'},
				  {'7','8','9','C'},
				  {'*','0','#','D'}};
int key_pressed(){
  for(int i=6;i<10;i++){
      for(int j=2;j<6;j++){
          digitalWrite(i, 0);
          if(digitalRead(j)==0)
            {
            digitalWrite(i, 1);
            return ((j-2)*4+(i-6));
          	}
      }
  digitalWrite(i, 1);
  }
  return -1;
}
void loop()
{
	int key=key_pressed();
    if(key!=last_pressed_key){
      if(key !=-1){
      		Serial.println(chars[key/4][key%4]);
      	}
      		last_pressed_key=key;
    	}
}


