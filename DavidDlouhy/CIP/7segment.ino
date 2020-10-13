#define SEG_A 13
#define SEG_B 12
#define SEG_C 11
#define SEG_D 10
#define SEG_E 9
#define SEG_F 7
#define SEG_G 6
#define SEG_H 5
#define BUT_1 2
bool tl;
bool old_tl;//reaguje pouze na hranu
int counter=0;
byte segments [8] = {SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G, SEG_H};
int segments_val [8] = {0, 0, 0, 0, 0, 0, 0, 0};
int val0 [8] = {1, 1, 1, 1, 1, 1, 0, 0};
  int val1 [8] = {0, 1, 1, 0, 0, 0, 0, 0};
  int val2 [8] = {1, 1, 0, 1, 1, 0, 1, 0};
  int val3 [8] = {1, 1, 1, 1, 0, 0, 1, 0};
  int val4 [8] = {0, 1, 1, 0, 0, 1, 1, 0};
  int val5 [8] = {1, 0, 1, 1, 0, 1, 1, 0};
  int val6 [8] = {0, 0, 1, 1, 1, 1, 1, 0};
  int val7 [8] = {1, 1, 1, 0, 0, 0, 0, 0};
  int val8 [8] = {1, 1, 1, 1, 1, 1, 1, 0};
  int val9 [8] = {1, 1, 1, 0, 0, 1, 1, 0};
void setup()
{ 
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(SEG_H, OUTPUT);
  pinMode(BUT_1, INPUT_PULLUP);
}
void loop()
{
  if(old_tl != digitalRead(BUT_1))
  {
    if(old_tl)
  	{
    	counter++;
      	if(counter ==10)
      	{
        	counter =0;
      	}
  	}
  	old_tl = digitalRead(BUT_1);  
  }
  delay(10);
  setNumber(counter, true);//nastavení
}
void setNumber(int number, bool dot)
{
  switch(number)
  {
    case 0:
    	setNumberAuto(val0, dot);
    break;
    case 1:
    	setNumberAuto(val1, dot);
    break;
    case 2:
    	setNumberAuto(val2, dot);
    break;
    case 3:
    	setNumberAuto(val3, dot);
    break;
    case 4:
    	setNumberAuto(val4, dot);
    break;
    case 5:
    	setNumberAuto(val5, dot);
    break;
    case 6:
    	setNumberAuto(val6, dot);
    break;
    case 7:
    	setNumberAuto(val7, dot);
    break;
    case 8:
    	setNumberAuto(val8, dot);
    break;
    case 9:
    	setNumberAuto(val9, dot);
    break;
  }
}
void setNumberAuto(int num[], bool dot)
{
  for(int i=0;i<=8;i++)
  {
    digitalWrite(segments[i],num[i]);
  }
  if(dot)
  {
      digitalWrite(SEG_H,1);
  }
}