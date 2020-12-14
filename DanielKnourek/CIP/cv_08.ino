int sLock;

#define keyboardRowStart 2
#define keyboardColStart 6
#define LEDgreen 12
#define LEDred 13

void setup()
{
  for(int i=2; i<=5; i++){
      pinMode(i, OUTPUT);
  }
  for(int i=6; i<=9; i++){
      pinMode(i, INPUT_PULLUP);
  }
  pinMode(LEDgreen, OUTPUT);
  pinMode(LEDred, OUTPUT);
  
  Serial.begin(9600);
  sLock = 0;
}

int password[4] = {1,2,3,4};

int Keys[4][4]={{1,2 ,3 ,10 },
                    {4,5 ,6 ,11 },
                    {7,8 ,9 ,12 },
                    {14 ,0 ,15 ,13 }};


int key = -1;
int clock = 0;
int sLEDgreen = 0;


void loop()
{  
  Serial.print("State: ");
  Serial.print(sLock);
  Serial.print(" | Clock: ");
  Serial.println(clock);
  //Read and keyboard
  bool keychange = newKey();

  //update clock
  updateClock();

  //state machine
  switch (sLock)
  {
  case -1: // fail
      digitalWrite(LEDred, 1);
    if(clock >= 1000){     
    {
      digitalWrite(LEDred, 0);
      sLock = 0;
      resetClock();
    }
    break;

  case 1: // waiting for key 2
    if (keychange)
    {      
      resetClock();
      if (key == password[1])
      {
        sLock = 2;
      }else
      {
        sLock = -1;
      }
    }
    if (clock >= 1000)
    {      
      resetClock();
      sLock = -1;
    }
  break;

  case 2: // waiting for key 3
    if (keychange)
    {      
      resetClock();
      if (key == password[2])
      {
        sLock = 3;
      }else
      {
        sLock = -1;
      }
    }
    if (clock >= 1000)
    {      
      resetClock();
      sLock = -1;
    }
  break;

  case 3: // waiting for key 4
    if (keychange)
    {      
      resetClock();
      if (key == password[3])
      {
        sLock = 4;
      }else
      {
        sLock = -1;
      }
    }
    if (clock >= 1000)
    {      
      resetClock();
      sLock = -1;
    }
  break;

  case 4: // open
      digitalWrite(LEDgreen, 1);
    if(clock >= 1000)
    {      
      digitalWrite(LEDgreen, 0);
      sLock = 0;
      resetClock();
    }
    break;

  case 0: // state ready
  default:
    if (clock >= 500)
    {
      resetClock();
      digitalWrite(LEDgreen, sLEDgreen);
      sLEDgreen = !sLEDgreen;
    }
    if (keychange)
    {
      sLEDgreen = 0;      
      digitalWrite(LEDgreen, sLEDgreen);
      if (key == password[0])
      {
        sLock = 1;
      }else
      {
        sLock = -1;
      }
      
      
    }
    break;
    }
  }
}

int lastTime = 0;
void updateClock()
{  
  clock = millis() - lastTime;
}
void resetClock()
{
  clock = 0;
  lastTime = millis();
}



bool newKey(){
  int keyPrev = key;
  int keytmp = checkKey(); 
  if( keytmp != keyPrev && keytmp != -1){     

    key = keytmp;
    return true;
  }
  else{
    return false;
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
