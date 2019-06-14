#define RED 9
#define GREEN 10
#define BLUE 11
#define interval 50

void light(byte R, byte G, byte B);
void pattern1(void);
void pattern2(void);
void pattern3(void);

byte mode=0;
boolean flag=0;

void setup() {
  Serial.begin(9600);
  Serial.println("Doing Setup");
  pinMode(13, INPUT);
  int t;
  t = millis();
  Serial.println("Select");
  while(millis() < t+3000){
    switch(mode){
      case 0:
        analogWrite(RED, 127);
        analogWrite(GREEN, 0);
        analogWrite(BLUE, 0);
        break;
      case 1:
        analogWrite(RED, 0);
        analogWrite(GREEN, 127);
        analogWrite(BLUE, 0);
        break;
      case 2:
        analogWrite(RED, 0);
        analogWrite(GREEN, 0);
        analogWrite(BLUE,127);
        break;
      default:
        mode = 0;
        break;
    }
    Serial.println(mode);
    if(digitalRead(12)){
      mode++;
      Serial.print("Mode ");
      Serial.print(mode);
      Serial.println("was Selected");
      t=millis();
      delay(500);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(mode){
    case 0:
      pattern1();
      break;
    case 1:
      pattern2();
      break;
    case 2:
      pattern3();
      break;
    default:
      break;
  }
}

void light(byte R, byte G, byte B){
  analogWrite(RED, R*0.7);
  analogWrite(GREEN, G);
  analogWrite(BLUE, B);
}

void pattern1(void){
  byte i;
  for(i=0; i<255; i++){
    analogWrite(GREEN, i);
    analogWrite(RED, 255-i);
    delay(interval);
  }
  for(i=0; i<255; i++){
    analogWrite(BLUE, i);
    analogWrite(GREEN, 255-i);
    delay(interval);
  }
  for(i=0; i<255; i++){
    analogWrite(RED, i);
    analogWrite(BLUE, 255-i);
    delay(interval);
  }   
}

void pattern2(void){
  byte i;
  for(i=0; i<255; i++){
    light(i, i, i);
    delay(interval);
  }
  for(i=255; i>0; i--){
    light(i, i, i);
    delay(interval);
  }
}

void pattern3(void){
  byte i;
  for(i=0; i<255; i++){
    light(i/2, 127+i/2, 255-i/2);
    delay(interval);
  }
  for(i=0; i<255; i++){
    light(127+i/2, 255-i/2, 127-i/2);
    delay(interval);
  }
  for(i=0; i<255; i++){
    light(255-i/2, 127-i/2, i/2);
    delay(interval);
  }
  for(i=0; i<255; i++){
    light(127-i/2, i/2, 127+i/2);
    delay(interval);
  }
}
