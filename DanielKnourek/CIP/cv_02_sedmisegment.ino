#define btnInput 19
void setup()
{
  for(int i = 6; i<=13; i++)
  {
  pinMode(i, OUTPUT);
  }
  pinMode(btnInput, INPUT_PULLUP);  
}

int numbers[13][8]={{0,0,0,0,0,0,1,1},//0
					          {1,0,0,1,1,1,1,1},//1
                 	  {0,0,1,0,0,1,0,1},//2
                  	{0,0,0,0,1,1,0,1},//3
                  	{1,0,0,1,1,0,0,1},//4
                  	{0,1,0,0,1,0,0,1},//5
                  	{0,1,0,0,0,0,0,1},//6
                  	{0,0,0,1,1,1,1,1},//7
                  	{0,0,0,0,0,0,0,1},//8
                  	{0,0,0,0,1,0,0,1} //9
  };
 int currentState = 0;

int btnPast=0;
void loop()
{  
  
    //Tlacitko
  int btnCurrent= digitalRead( btnInput );
  if(btnPast==1 && btnCurrent!=1){
  	currentState++;
    if(currentState>=9){
    	currentState = 0;
    }
  }
  btnPast = btnCurrent;  
  delay(10);
  DrawSegment( currentState );
  
}

void DrawSegment(int number){
  for(int i=6;i<=12;i++)
  {
    digitalWrite(i,numbers[number][i-6]);
  }
}