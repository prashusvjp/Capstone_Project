int RED_LED=13;
int YELLOW_LED=12;
int GREEN_LED=8;
int buttonPin=2;
int button_state=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // button_state = digitalRead(buttonPin);
  // Serial.println(button_state);
  digitalWrite(RED_LED,HIGH);
  
  // if (button_state == HIGH) {
  //   // turn LED on:
  //   digitalWrite(GREEN_LED, HIGH);
  //   digitalWrite(RED_LED, LOW);
  // } else {
  //   // turn LED off:
  //   digitalWrite(RED_LED, HIGH);
  //   digitalWrite(GREEN_LED,LOW);
  // }
  // put your main code here, to run repeatedly:
  // digitalWrite(RED_LED,HIGH);
  // digitalWrite(YELLOW_LED,LOW);
  // digitalWrite(GREEN_LED,LOW);
  // delay(1000);
  // digitalWrite(YELLOW_LED,HIGH);
  // digitalWrite(RED_LED,LOW);
  // digitalWrite(GREEN_LED,LOW);
  // delay(1000);
  // digitalWrite(YELLOW_LED,LOW);
  // digitalWrite(RED_LED,LOW);
  // digitalWrite(GREEN_LED,HIGH);
  // delay(1000);

}
