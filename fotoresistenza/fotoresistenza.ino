//Pin connected to SH_CP of 74HC595
int clockPin = 8; //pin 11

//Pin connected to ST_CP of 74HC595
int latchPin = 9; //pin 12

//Pin connected to DS of 74HC595
int dataPin = 10; //pin 14

int tempo = 50;
int led = 7;
int res = A0;

void setup(){
    pinMode(dataPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(led, OUTPUT);
    pinMode(res, INPUT);
    Serial.begin(9600);
}

byte var[] = {
  B00000000,
  B11111111,
  B01111111,
  B00111111,
  B00011111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
};

int i = 8;

void loop(){
  
  Serial.println(String(analogRead(res)));

  if(analogRead(res) > 100 && analogRead(res) < 200){
    i = 1;
  }
  if(analogRead(res) > 200 && analogRead(res) < 300){
    i = 2;
  }
  if(analogRead(res) > 300 && analogRead(res) < 400){
    i = 3;
  }
  if(analogRead(res) > 400 && analogRead(res) < 500){
    i = 4;
  }
  if(analogRead(res) > 500 && analogRead(res) < 600){
    i = 5;
  }
  if(analogRead(res) > 600 && analogRead(res) < 700){
    i = 6;
  }
  if(analogRead(res) > 700 && analogRead(res) < 800){
    i = 7;
  }
  if(analogRead(res) > 800){
    i = 0;
  }

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, var[i]);
  digitalWrite(latchPin, HIGH);
  delay(5);

}
