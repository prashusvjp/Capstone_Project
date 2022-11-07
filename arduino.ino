int i=0;
unsigned long int j=0;
const int EnableL = 5;
const int HighL = 6;       // LEFT SIDE MOTOR
const int LowL =7;

const int EnableR = 10;
const int HighR = 8;       //RIGHT SIDE MOTOR
const int LowR =9;

bool Left_Indicator_State=false;
bool Right_Indicator_State=false;

const int D0 = 12;       //Raspberry pin 21    LSB
const int D1 = 13;       //Raspberry pin 22
const int D2 = 2;       //Raspberry pin 23
const int D3 = 3;       //Raspberry pin 24    MSB

int a,b,c,d,data=8;
void LaneChange();
void Object();

void Data()
{
  a = digitalRead(D0);
  b = digitalRead(D1);
  c = digitalRead(D2);
  d = digitalRead(D3);

  data = 8*d+4*c+2*b+a;
  Serial.println(data);
}



void setup() {

pinMode(EnableL, OUTPUT);      
pinMode(HighL, OUTPUT);
pinMode(LowL, OUTPUT);


pinMode(EnableR, OUTPUT);
pinMode(HighR, OUTPUT);
pinMode(LowR, OUTPUT);

pinMode(D0, INPUT_PULLUP);
pinMode(D1, INPUT_PULLUP);
pinMode(D2, INPUT_PULLUP);
pinMode(D3, INPUT_PULLUP);
Serial.begin(9600);
}

void Forward()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,255);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,255);
  
}


void Backward()
{
  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);
  analogWrite(EnableL,255);

  digitalWrite(HighR, HIGH);
  digitalWrite(LowR, LOW);
  analogWrite(EnableR,255);
  
}

void Stop()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,0);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,0);
  
}
 

void Left1()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,160);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,255);
  
}

void Left2()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,90);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,255);
  
}


void Left3()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,50);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,255);
  
}

void Right1()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,255);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,160);  
  
}
void Right2()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,255);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,90);   
  
}

void Right3()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,255);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,50);   
}

void indicateLeftTurn(){
    Left_Indicator_State=!Left_Indicator_State;
    if(Left_Indicator_State){
      //Switch On Left Indicator
    }else{
      //Switch Off Left Indicator
    }
}

void indicateRightTurn(){
    Right_Indicator_State=!Right_Indicator_State;
    if(Right_Indicator_State){
      //Switch On Right Indicator
    }else{
      //Switch Off Right Indicator
    }
}

void Traffic(){
  Stop(); 
}

void loop() 
{
  // if(j > 25000)
  // {
  //   Lane_Change();
  //   i = 0;
  //   j = 0;
  // }

  Data();
  switch(data){
    case 15:Forward();
      j+=(i>0)?1:0;
      break;
    case 1:Right1();
      j+=(i>0)?1:0;
      break;
    case 2:Right2();
      j+=(i>0)?1:0;
      break;
    case 3:Right3();
      j+=(i>0)?1:0;
      break;
    case 4:Left1();
      j+=(i>0)?1:0;
      break;
    case 5:Left2();
      j+=(i>0)?1:0;
      break;
    case 6:Left3();
      j+=(i>0)?1:0;
      break;
    case 7:Backward();break;
    case 8:Stop();break;
    case 9:indicateLeftTurn();break;
    case 10:indicateRightTurn();break;
    case 11:Traffic();break;
    default:Stop();break;
  }
}

/*void UTurn()
{
  analogWrite(EnableL, 0);
  analogWrite(EnableR, 0);
  delay(400);

  analogWrite(EnableL, 250);
  analogWrite(EnableR, 250);    //forward
  delay(1000);

  analogWrite(EnableL, 0);
  analogWrite(EnableR, 0);
  delay(400);

  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);
  digitalWrite(HighR, LOW);   //   left
  digitalWrite(LowR, HIGH);
  analogWrite(EnableL, 255);
  analogWrite(EnableR, 255);
  delay(700);

  analogWrite(EnableL, 0);
  analogWrite(EnableR, 0);
  delay(400);

  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  digitalWrite(HighR, LOW);   // forward
  digitalWrite(LowR, HIGH);
  analogWrite(EnableL, 255);
  analogWrite(EnableR, 255);
  delay(900);

  analogWrite(EnableL, 0);
  analogWrite(EnableR, 0);
  delay(400);

  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);
  digitalWrite(HighR, LOW);    //left
  digitalWrite(LowR, HIGH);
  analogWrite(EnableL, 255);
  analogWrite(EnableR, 255);
  delay(700);


  analogWrite(EnableL, 0);
  analogWrite(EnableR, 0);
  delay(1000);



  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  digitalWrite(HighR, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL, 150);
  analogWrite(EnableR, 150);
  delay(300);
}*/

/*
void Object()
{

  analogWrite(EnableL, 0);
  analogWrite(EnableR, 0);            //stop
  delay(1000);

  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);
  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);        //left
  analogWrite(EnableL, 250);
  analogWrite(EnableR, 250);
  delay(500);

  analogWrite(EnableL, 0);
  analogWrite(EnableR, 0);            //stop
  delay(200);

  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);           //forward
  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableL, 255);
  analogWrite(EnableR, 255);
  delay(1000);

  analogWrite(EnableL, 0);           //stop
  analogWrite(EnableR, 0);
  delay(200);

  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  digitalWrite(HighR, HIGH);         //right
  digitalWrite(LowR, LOW);
  analogWrite(EnableL, 255);
  analogWrite(EnableR, 255);
  delay(500);

  analogWrite(EnableL, 0);               //stop
  analogWrite(EnableR, 0);
  delay(1000);

  
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  digitalWrite(HighR, LOW);       // forward
  digitalWrite(LowR, HIGH);
  analogWrite(EnableL, 150);
  analogWrite(EnableR, 150);
  delay(500);

   i  = i+1;
}


void Lane_Change()
{

  analogWrite(EnableL, 0);
  analogWrite(EnableR, 0);            //stop
  delay(1000);

  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  digitalWrite(HighR, HIGH);
  digitalWrite(LowR, LOW);        //Right
  analogWrite(EnableL, 250);
  analogWrite(EnableR, 250);
  delay(500);

  analogWrite(EnableL, 0);
  analogWrite(EnableR, 0);            //stop
  delay(200);

  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);           //forward
  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableL, 255);
  analogWrite(EnableR, 255);
  delay(800);

  analogWrite(EnableL, 0);           //stop
  analogWrite(EnableR, 0);
  delay(200);

  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);
  digitalWrite(HighR, LOW);         //LEFT
  digitalWrite(LowR, HIGH);
  analogWrite(EnableL, 255);
  analogWrite(EnableR, 255);
  delay(500);

  analogWrite(EnableL, 0);               //stop
  analogWrite(EnableR, 0);
  delay(1000);

  
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  digitalWrite(HighR, LOW);       // forward
  digitalWrite(LowR, HIGH);
  analogWrite(EnableL, 150);
  analogWrite(EnableR, 150);
  delay(500);

}*/