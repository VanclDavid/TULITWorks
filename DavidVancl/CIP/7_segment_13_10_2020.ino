#define SEGMENT_START 2
#define SEGMENT_END 9
#define SEGMENT_LENGTH 8
#define BUTTON_INPUT 10
int numbers[10][SEGMENT_LENGTH] = {
  {1,1,1,1,1,1,0,0},{0,1,1,0,0,0,0,0},{1,1,0,1,1,0,1,0},{1,1,1,1,0,0,1,0},{0,1,1,0,0,1,1,0},
  {1,0,1,1,0,1,1,0},{1,0,1,1,1,1,1,0},{1,1,1,0,0,1,0,0},{1,1,1,1,1,1,1,0},{1,1,1,0,0,1,1,0}
};
void setup(){
  for (int i = SEGMENT_START; i <= SEGMENT_END; i++){
  	pinMode(i,OUTPUT);
  }
  pinMode(BUTTON_INPUT,INPUT_PULLUP);
}
int touches,now = 0;
int lastStuff = HIGH;
void loop(){
  if((now = digitalRead(BUTTON_INPUT)) != lastStuff){
    if (now == HIGH && lastStuff == LOW) touches++;
    lastStuff = now;
  }
  printSegment(numbers[touches]);
}
void printSegment(int number[]){
  for (int i = SEGMENT_START; i <= SEGMENT_END; i++){
	digitalWrite(i,number[(i - SEGMENT_START)]);
  }
}