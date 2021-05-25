int segPins[]={4,5,7,8,9,10,6,11}; //{a,b,c,d,e,f,g,.}
int displayPins[3]={3,12,13};
int displayBuffer[3];
int swt=2;
int pb=1;
int i=0;
int j=0;
int k=0;
unsigned long  startTime=0;
unsigned long endTime;

int segCode[11][8]= {
  //{a,b,c,d,e,f,g,.}
    {0,0,0,0,0,0,1,1},//0
    {1,0,0,1,1,1,1,1},//1
    {0,0,1,0,0,1,0,1},//2
    {0,0,0,0,1,1,0,1},//3
    {1,0,0,1,1,0,0,1},//4
    {0,1,0,0,1,0,0,1},//5
    {0,1,0,0,0,0,0,1},//6
    {0,0,0,1,1,1,1,1},//7
    {0,0,0,0,0,0,0,1},//8
    {0,0,0,0,1,0,0,1},//9
    {1,1,1,1,1,1,1,0},//.
};

void setup()
{
  for(int i=0; i<8; i++){
  	pinMode(segPins[i],OUTPUT);
  }
  pinMode(displayPins[0], OUTPUT);
  pinMode(displayPins[1], OUTPUT);
  pinMode(displayPins[2], OUTPUT);
  pinMode(swt, INPUT);
  pinMode(pb, INPUT);
  displayBuffer[0]=0;
  displayBuffer[1]=0;
  displayBuffer[2]=0;
}

void loop()
{
  int swstate=digitalRead(swt);
  int pbstate=digitalRead(pb);
  if(pbstate==HIGH){
    Display(displayBuffer[2],displayBuffer[1],displayBuffer[0]);
    displayBuffer[0]=0;
    displayBuffer[1]=0;
    displayBuffer[2]=0;
    i=0;
    j=0;
    k=0;
  }
  else{
    if(swstate==HIGH){
      Display(displayBuffer[2],displayBuffer[1],displayBuffer[0]);
      endTime=millis();
      if((endTime-startTime)>=100){
        if(++i>9)
        {
          i=0;

        if(++j>9)
        {
          j=0;
        if(++k>9)
        {
          k=0;  
        }
        }
        }
        displayBuffer[0]=i;
        displayBuffer[1]=j;
        displayBuffer[2]=k;
        startTime=endTime;
      }
    }
    else{
      Display(displayBuffer[2],displayBuffer[1],displayBuffer[0]);
    }
  }
}

void Display(int digit2, int digit1, int digit0){
  digitalWrite(displayPins[0],HIGH);
  digitalWrite(displayPins[1],LOW);
  digitalWrite(displayPins[2],LOW);
  setSegments(digit0);
  delay(5);
  digitalWrite(displayPins[0],LOW);
  digitalWrite(displayPins[1],HIGH);
  digitalWrite(displayPins[2],LOW);
  setSegments(digit1);
  delay(5);
  setDecimal(digit1); //to set the decimal at digit1 form left
  delay(5);
  digitalWrite(displayPins[0],LOW);
  digitalWrite(displayPins[1],LOW);
  digitalWrite(displayPins[2],HIGH);
  setSegments(digit2);
  delay(5);
}

void setSegments(int n){
  for(int i=0; i<8; i++){
  	digitalWrite(segPins[i],segCode[n][i]);
  }
}
void setDecimal(int n){
  for(int i=0; i<8; i++){
  	digitalWrite(segPins[i],segCode[10][i]);
  }
}