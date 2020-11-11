#define PINS_START    2
#define LAST_ROW_PIN  5
#define PINS_END      9
char buttons_text[4][4] = {{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};
char last_type = '%';
bool was_clicked = false;
void setup(){
  for(int i = PINS_START; i <= PINS_END;i++){
    if (i <= LAST_ROW_PIN) pinMode(i,INPUT_PULLUP);
    else pinMode(i,OUTPUT);
  }
  Serial.begin(9600);
}
void loop(){
  was_clicked = false;
  for(int i = (LAST_ROW_PIN + 1); i <= PINS_END;i++){
    digitalWrite(i,0);
    for(int j = PINS_START; j <= LAST_ROW_PIN; j++){
      	if(digitalRead(j) == 0){
          was_clicked = true;
          if(last_type != buttons_text[j-2][i-6]){
          	Serial.print(buttons_text[j-2][i-6]);
            last_type = buttons_text[j-2][i-6];
          }
        }
    }
    digitalWrite(i,1);
  }
  if (was_clicked == false) last_type = '%';
}