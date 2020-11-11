
int NahodnaLEDka;

#define keyboardRowStart 2
#define keyboardColStart 6

void setup()
{
  for(int i=2; i<=5; i++){
      pinMode(i, OUTPUT);
  }
  for(int i=6; i<=9; i++){
      pinMode(i, INPUT_PULLUP);
  }
  
  Serial.begin(9600);
}

int Keys[4][4]={{1,2 ,3 ,10 },
                    {4,5 ,6 ,11 },
                    {7,8 ,9 ,12 },
                    {14 ,0 ,15 ,13 }};

int key = -1;

void loop()
{
  int keyPrev = key;
  key = checkKey();

  if( key != keyPrev && key != -1){  
    Serial.print("Keyboard: ");
    Serial.println(key);
  }  
}

int checkKey(){
  int row=-1;
  int col=-1;
  for (int i = keyboardRowStart; i <= keyboardRowStart + 3; i++)
  {
    digitalWrite(i, 0);
    for (int j= keyboardColStart ;j<= keyboardColStart+3;j++)
      {
       if(digitalRead(j)==0)
       {
         row=i - keyboardRowStart;
         col=j - keyboardColStart;
       } 
      }
    digitalWrite(i, 1); 
  }
  if(row < 0) return -1;
  return Keys[row][col];
}
