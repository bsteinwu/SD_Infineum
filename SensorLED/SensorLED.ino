#include <SoftwareSerial.h>
//SoftwareSerial mySerial(3, 5); // RX, TX
float x = 0;
String command;

//LED row pins
int ss0 = 8;
int ss1 = 9;
int ss2 = 10;

//LED col pins
int s0 = 5;
int s1 = 6;
int s2 = 7;

//LED high/low pins
int z = 3;
int zz = 4;
bool ledOn;

//Sensor row pins
int sen0 = 11;
int sen1 = 12;
int sen2 = 13;

//sensor reading pin & variable
int sensor = A3;
int sensorNinne = A4;
int designatedSensor;
int reading;

int designatedLED;
int oldLED = 0;
int designatedColumn = 4;
int designatedRow = 2;

bool onSensor;


void setup() {
  Serial.begin(115200);
  
  pinMode(z, OUTPUT);
  pinMode(zz, OUTPUT);
  
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(ss0, OUTPUT);
  pinMode(ss1, OUTPUT);
  pinMode(ss2, OUTPUT);
  pinMode(sen0, OUTPUT);
  pinMode(sen1, OUTPUT);
  pinMode(sen2, OUTPUT);

}


void loop() {
  delay(100);
  //digitalWrite(z,LOW);
  //digitalWrite(zz,LOW);
  //Serial.println("Waiting for command");
  command = "";

  while(!Serial.available()){
  }
  
  if (Serial.available()) // Check if there is Incoming Data in the Serial Buffer.
  {
    while (Serial.available()){
     command = Serial.readString();
     
     if(command == "LED"){
        LEDLoop();
        break;
      }
      else if(command == "sensor" || command == "Sensor"){
        sensorLoop();
        break;
      }
    }
  }
   
  
}
//________________________________________________________________________________


void LEDLoop(){

  //Serial.println("LED Loop");

  designatedRow = 0;
  designatedColumn = 0;
  designatedLED = 0;

while(!Serial.available()){
  }
  
  while (Serial.available()){
     designatedLED = Serial.readString().toInt();
  }

  

   x = designatedLED/9.0;
   designatedRow = floor(designatedLED/9);
   if(designatedRow != x){
    designatedRow++;
   }
   
   //Serial.print("LED in row: ");
   //Serial.println(designatedRow);

   
   designatedColumn = (designatedLED + 9) % 9;
   if(designatedColumn == 0){
    designatedColumn = 9;
   }

   
   //Serial.print("LED in column: ");
   //Serial.println(designatedColumn);
   
  digitalWrite(z, HIGH);
  digitalWrite(zz, LOW);

  if(oldLED == designatedLED){
    digitalWrite(z, LOW);
    digitalWrite(zz, LOW);
  }

  if(designatedColumn == 1){
    digitalWrite(s0, LOW);
    digitalWrite(s1, LOW);
    digitalWrite(s2, LOW);
  } else if(designatedColumn == 2){
    digitalWrite(s0, HIGH);
    digitalWrite(s1, LOW);
    digitalWrite(s2, LOW);
  } else if(designatedColumn == 3){
    digitalWrite(s0, LOW);
    digitalWrite(s1, HIGH);
    digitalWrite(s2, LOW);
  } else if(designatedColumn == 4){
    digitalWrite(s0, HIGH);
    digitalWrite(s1, HIGH);
    digitalWrite(s2, LOW);
  }else if(designatedColumn == 5){
    digitalWrite(s0, LOW);
    digitalWrite(s1, LOW);
    digitalWrite(s2, HIGH);
  } else if(designatedColumn == 6){
    digitalWrite(s0, HIGH);
    digitalWrite(s1, LOW);
    digitalWrite(s2, HIGH);
  } else if(designatedColumn == 7){
    digitalWrite(s0, LOW);
    digitalWrite(s1, HIGH);
    digitalWrite(s2, HIGH);
  }else if(designatedColumn == 8){
    digitalWrite(s0, HIGH);
    digitalWrite(s1, HIGH);
    digitalWrite(s2, HIGH);
  } else if(designatedColumn == 9){ 
    digitalWrite(z,LOW);
    digitalWrite(zz,HIGH);
  } 



  if(designatedRow == 1){
    digitalWrite(ss0, LOW);
    digitalWrite(ss1, LOW);
    digitalWrite(ss2, LOW);
  } else if(designatedRow == 2){
    digitalWrite(ss0, HIGH);
    digitalWrite(ss1, LOW);
    digitalWrite(ss2, LOW);
  } else if(designatedRow == 3){
    digitalWrite(ss0, LOW);
    digitalWrite(ss1, HIGH);
    digitalWrite(ss2, LOW);
  } else if(designatedRow == 4){
    digitalWrite(ss0, HIGH);
    digitalWrite(ss1, HIGH);
    digitalWrite(ss2, LOW);
  } else if(designatedRow == 5){
    digitalWrite(ss0, LOW);
    digitalWrite(ss1, LOW);
    digitalWrite(ss2, HIGH);
  }

  //Serial.println("End of LED Loop");
  oldLED = designatedLED;
  delay(2000);
}
//_______________________________________________________________________________



void sensorLoop(){
  
  //Serial.println("Sensor Loop");

  while(!Serial.available()){
  }
  
  while(Serial.available()){
     designatedLED = Serial.readString().toInt();
  }
  
   x = designatedLED/9.0;
   designatedRow = floor(designatedLED/9);
   if(designatedRow != x){
    designatedRow++;
   }
   
   //Serial.print("Sensor in row: ");
   //Serial.println(designatedRow);

   
   designatedColumn = (designatedLED + 9) % 9;
   if(designatedColumn == 0){
      designatedColumn = 9;
   }

   
   //Serial.print("Sensor in column: ");
   //Serial.println(designatedColumn);


  digitalWrite(z, HIGH);
  digitalWrite(zz, LOW);


  if(designatedColumn == 1){
    digitalWrite(s0, LOW);
    digitalWrite(s1, LOW);
    digitalWrite(s2, LOW);
  } else if(designatedColumn == 2){
    digitalWrite(s0, HIGH);
    digitalWrite(s1, LOW);
    digitalWrite(s2, LOW);
  } else if(designatedColumn == 3){
    digitalWrite(s0, LOW);
    digitalWrite(s1, HIGH);
    digitalWrite(s2, LOW);
  } else if(designatedColumn == 4){
    digitalWrite(s0, HIGH);
    digitalWrite(s1, HIGH);
    digitalWrite(s2, LOW);
  }else if(designatedColumn == 5){
    digitalWrite(s0, LOW);
    digitalWrite(s1, LOW);
    digitalWrite(s2, HIGH);
  } else if(designatedColumn == 6){
    digitalWrite(s0, HIGH);
    digitalWrite(s1, LOW);
    digitalWrite(s2, HIGH);
  } else if(designatedColumn == 7){
    digitalWrite(s0, LOW);
    digitalWrite(s1, HIGH);
    digitalWrite(s2, HIGH);
  }else if(designatedColumn == 8){
    digitalWrite(s0, HIGH);
    digitalWrite(s1, HIGH);
    digitalWrite(s2, HIGH);
  } else if(designatedColumn == 9){ 
    digitalWrite(z,LOW);
    digitalWrite(zz,HIGH);
  } 


  if(designatedRow == 1){
    digitalWrite(sen0, LOW);
    digitalWrite(sen1, LOW);
    digitalWrite(sen2, LOW);

    digitalWrite(ss0, HIGH);
    digitalWrite(ss1, LOW);
    digitalWrite(ss2, LOW);
  } else if(designatedRow == 2){
    digitalWrite(sen0, HIGH);
    digitalWrite(sen1, LOW);
    digitalWrite(sen2, LOW);

    digitalWrite(ss0, LOW);
    digitalWrite(ss1, LOW);
    digitalWrite(ss2, LOW);
  } else if(designatedRow == 3){
    digitalWrite(sen0, LOW);
    digitalWrite(sen1, HIGH);
    digitalWrite(sen2, LOW);

    digitalWrite(ss0, LOW);
    digitalWrite(ss1, LOW);
    digitalWrite(ss2, LOW);
  } else if(designatedRow == 4){
    digitalWrite(sen0, HIGH);
    digitalWrite(sen1, HIGH);
    digitalWrite(sen2, LOW);

    digitalWrite(ss0, LOW);
    digitalWrite(ss1, LOW);
    digitalWrite(ss2, LOW);
  } else if(designatedRow == 5){
    digitalWrite(sen0, LOW);
    digitalWrite(sen1, LOW);
    digitalWrite(sen2, HIGH);

    digitalWrite(ss0, LOW);
    digitalWrite(ss1, LOW);
    digitalWrite(ss2, LOW);
  }
  
  delay(5);
  
  reading = analogRead(sensor);
  //Serial.print("Sensor reading is ");
  //Serial.println(reading);

  if(reading > 10){
    onSensor = true;
    Serial.print("1");
  } else{
    onSensor = false;
    Serial.print("0");
  }

  //digitalWrite(z, LOW);   will this risk having an LED improperly go on?
  //digitalWrite(zz, LOW);

}
//____________________________________________________________________________________
