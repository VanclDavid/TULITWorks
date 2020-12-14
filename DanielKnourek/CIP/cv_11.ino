#define LED1 10
#define LED2 11
#define btn 12
#define segmentStart 2

int currentTime = 0;

void setup()
{
  for(int i = segmentStart; i<= segmentStart + 6; i++){
  pinMode(i, OUTPUT);
  }
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(btn, INPUT_PULLUP);  

  Serial.begin(9600);
}

int numbers[13][7]={{1,1,1,1,1,1,0},//0
					          {0,1,1,0,0,0,0},//1
                 	  {1,1,0,1,1,0,1},//2
                  	{1,1,1,1,0,0,1},//3
                  	{0,1,1,0,0,1,1},//4
                  	{1,0,1,1,0,1,1},//5
                  	{1,0,1,1,1,1,1},//6
                  	{1,1,1,0,0,0,0},//7
                  	{1,1,1,1,1,1,1},//8
                  	{1,1,1,1,0,1,1} //9
  };
  //StateMachines  
  int ScommandListener = 0;
  int Stimer = 0;

    //Serial command Listener vars
    String command = String("");
    char incomingChar = '\0';
    //vars
    int vLED1 = 0, vLED2 = 0, vTLAC = 0, vSEG = 0;

    //1s Timer vars
    int startTime = 0;
    int startTimeLog = 0;

  //Templates  
  template<typename T> void SerialLogPrint(T log,bool newLine){
    if (currentTime - startTimeLog < 500) return;
    if (newLine)
    {
      Serial.println(log);
      startTimeLog = currentTime;
    }else{    
      Serial.print(log);
    }  
  }
  template<typename T> void SerialLog(T log){SerialLogPrint(log, false);}
  template<typename T> void SerialLogln(T log){SerialLogPrint(log, true);}
  //Loop start
void loop(){

  currentTime = millis();

  // ----- Serial command Listener -----
  switch (ScommandListener){
  //StandBy for command start
  case 1:
      if (ListenChar(incomingChar) && incomingChar == '*'){
        Stimer = 1;
        ScommandListener = 2;
      }      
    break;

  //Reading bytes of command
  case 2:
      if (Stimer == 0){
        ScommandListener = 0;
        break;
      }
      while(ListenChar(incomingChar)){
        if (incomingChar == '#'){          
          Stimer = 0;
          ScommandListener = 3;
        }else{
          command += incomingChar;
          Stimer = 1;
        }  
      }
      
    
    break;  

  //Trying to execute command  
  case 3:
    executeCommand(command);
    ScommandListener = 0;
    break;
  
  
  // init / reset
  case 0:
  default:
    command = "";
    ScommandListener = 1;
    break;
  } 


  // ----- 1s Timer -----
  switch (Stimer)
  {
  case 1:
    startTime = currentTime;
    Stimer = 2;
    break;

  case 2:
    if (currentTime - startTime >= 1000)
    {
      Stimer = 0;
    }    
    break;
  
  //Finished
  case 0:
  default:

    break;
  }
}

void executeCommand(String command){
    String target = command.substring(0, command.indexOf('='));
    String val = command.substring(target.length()+1);
    
    if (target == "LED1")
    {
      if (val.length() >= 1) // set
      {
        vLED1 = val.toInt();
        digitalWrite(LED1, vLED1);
      }else // get
      {        
        Serial.println(vLED1);
      }      
    }else if (target == "LED2")
    {
      if (val.length() >= 1) // set
      {
        vLED2 = val.toInt();
        digitalWrite(LED2, vLED2);
      }else // get
      {        
        Serial.println(vLED2);
      } 
    }else if (target == "TLAC")
    {      
      Serial.println(vTLAC);
    }else if (target == "SEG")
    {
      if (val.length() >= 1) // set
      {
        vSEG = val.toInt();
        DrawSegment(vSEG);
      }else // get
      {        
        Serial.println(vSEG);
      } 
    }else
    {
      Serial.println("Command ERROR !");
    }
    return;
}

void DrawSegment(int number){
  for(int i=segmentStart;i<=segmentStart+6;i++){
    digitalWrite(i,numbers[number][i-segmentStart]);
  }
}

bool ListenChar(char &incomingByte){  
  if (Serial.available() > 0) {
        incomingByte = Serial.read();
        return true;
  }
  return false;
}
