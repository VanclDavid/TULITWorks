int numbers[10][7] = {
  {1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},{1,0,1,1,1,1,1},{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,0,0,1,1}
};
int counter;
int state;
#define S1 !digitalRead(3)
#define S2 !digitalRead(2)
void setup()
{
  state=0;
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  for(int i=13;i>5;i--){
  	  pinMode(i, OUTPUT);
  }
  
}
void loop()
{
  switch(state){
  	case 0:
    counter=0;
    state=1;
    break;
    case 1:
    if(S1==0 && S2==1){state=2;counter++;showNumber(counter);}
    if(S1==1 && S2==1){state=4;counter--;showNumber(counter);}
    break;
    case 2:
    if(S1==1 && S2==0){state=3;counter++;showNumber(counter);}
    if(S1==0 && S2==0){state=1;counter--;showNumber(counter);}
    break;
    case 3:
    if(S1==1 && S2==1){state=4;counter++;showNumber(counter);}
    if(S1==0 && S2==1){state=2;counter--;showNumber(counter);}
    break;
    case 4:
    if(S1==0 && S2==0){state=1;counter++;showNumber(counter);}
    if(S1==1 && S2==0){state=3;counter--;showNumber(counter);}
    break;
  }  
}
void showNumber(int number){
	int index=0;
  for(int i=13;i>6;i--){
  	  digitalWrite(i, numbers[number%10][index]);
  	index++;
  }
}