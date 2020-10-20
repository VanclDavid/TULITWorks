#define LED1 8
#define LED2 9
#define BTN1 2

int sL1 = 0;
int sL2 = 0;


void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BTN1, INPUT_PULLUP);
}

int prevTime = 0;
int clickCount = 0;

void loop()
{

  int currentTime = millis();

  // LED1
  switch (sL1)
  {
  case 1:
    if ((currentTime - prevTime) >= 1000)
    {
      sL1 = 0;
      digitalWrite(LED1, 0);
      prevTime = currentTime;
    }
    
    break;

  case 0:
  default:
    if ((currentTime - prevTime) >= 1000)
    {
      sL1 = 1;
      digitalWrite(LED1, 1);
      prevTime = currentTime;
    }
    break;
  }
  // LED2
  registerClick();

  switch (sL2)
  {
  case 1:
    if (clickCount >= 3)
    {
      sL2 = 0;
      digitalWrite(LED1, 0);
      clickCount = 0;
    }    
    break;

  case 0:
  default:
    if (clickCount >= 3)
    {
      sL2 = 1;
      digitalWrite(LED1, 1);
      clickCount = 0;
    } 
    break;
  }
}

int btnPast = 0;

void registerClick(){
  int btnCurrent = digitalRead(BTN1); 
  
  Serial.println(clickCount);
  
  if ( btnPast == 1 && btnCurrent == 0)
  {
    clickCount++;
  }
  btnPast = btnCurrent;
  
}