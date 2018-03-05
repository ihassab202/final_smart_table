#include<Servo.h>

//----- LAPTOP -----

int tp=8; //push button
int td=9; //push button

bool tflg = true;// flag for drawer .........if drawer open flag high

Servo ser1;
Servo ser2;
Servo sel1;
Servo sel2;
Servo m1;//medicine drawer servo
Servo m2;
Servo m3;

//----- DORG -----
int op=13;//driver direction of opening
int cs=12;//driver cirection of closing
int b=3;//micro button
int b2=4; //second micro button
int EN=11;//enable
bool dflg = false;
//int d = analogRead(0);
//int 
//int rel = 5200;//put the pin no. of the relay
//----- END -----
int yop=0;

void setup() {
// put your setup code here, to run once:
ser1.attach(2);
ser2.attach(10);
sel1.attach(6);
sel2.attach(5);
sel1.write(10);
     ser1.write(55);
     delay(100);
     ser2.write(20);
     sel2.write(50);

Serial.begin(9600);
 
   // pinMode(b,INPUT_PULLUP);
    pinMode(td,INPUT_PULLUP);
    pinMode(tp,INPUT_PULLUP);
    tflg = false;

/*
     ser1.write(0);
     sel2.write(75); 
     delay(250);
     ser2.write(70);
     sel1.write(30); // BACK TO 30 
*/
//----- DORG -----


pinMode(op , OUTPUT);
pinMode(cs , OUTPUT);
//pinMode(rel , OUTPUT);
pinMode(b2, INPUT_PULLUP);
//digitalWrite(rel,HIGH);
}

void loop() {
  Serial.println(tflg);
 /* Serial.print("button 1 =");
  Serial.println(digitalRead(b));
  Serial.print("button 2 =");
  Serial.println(digitalRead(b2));
  */// put your main code here, to run repeatedly:
 //v = Serial.parseInt();
 int ad = analogRead(0);
 delay(15);
 //Serial.println(ad);
    yop = Serial.parseInt();
 delay(10);
 if(yop == 5){
digitalWrite(op,HIGH);
digitalWrite(cs,LOW);
analogWrite(EN,200);
while(true){
  
if(digitalRead(b)==1){
break;}
delay(10);
}


digitalWrite(op,LOW);
digitalWrite(cs,LOW);
analogWrite(EN,0);
}

 if(yop == 2){
digitalWrite(op,LOW);
digitalWrite(cs,HIGH);
analogWrite(EN,200);
delay(4000);
digitalWrite(op,LOW);
digitalWrite(cs,LOW);
analogWrite(EN,0);
}



  if((digitalRead(td) == 0) && (tflg == true)){
    Serial.println("test");
    ser1.write(25);
     sel2.write(10); 
     delay(100);
     ser2.write(50);
     sel1.write(65);
     /*sel1.write(70);
     ser1.write(55);
     delay(100);
     ser2.write(30);
     sel2.write(0);*/

      tflg = false;
        
    } 
    
    if((digitalRead(tp) == 0) && (tflg == false)){
Serial.println("close");
     sel1.write(10);
     ser1.write(55);
     delay(100);
     ser2.write(20);
     sel2.write(50);


      tflg = true;     
       
      }

//----- DORG -----

      int d = analogRead(0);

      if((d < 200) && (dflg == true)){ // pot rotate right close ----- using pot to close drawer
      
        //Serial.print(d);
        Serial.println("  open");
        digitalWrite(cs , HIGH);
        digitalWrite(op , LOW);
        analogWrite(EN , 200);
        delay(1000);
        while(true){
        delay(10);
        if(digitalRead(b2)==0){
        break;}}
        analogWrite(EN , 0);
        
        dflg = false;
        //Serial.println(dflg);
        
        }

        if((d <= 400) && (d >= 200)){// if in the middle mate3mlsh 7aga (im not sure el commentaya dy sa7)

        Serial.print(" close");
        //Serial.println(d);
        digitalWrite(cs , LOW);
        digitalWrite(op , LOW);
        analogWrite(EN , 0);
        //Serial.println(dflg);
                
        }
        
      if((d > 400) && (dflg == false)){  // pot rotate left open -----usng pot to open drawer

       // Serial.print(" d2");
       // Serial.println(d);
        digitalWrite(cs , LOW);
        digitalWrite(op , HIGH);
        analogWrite(EN , 200);
        delay(1000);
        while(true){
        delay(10);
        if(digitalRead(b)==0){
        break;}
        }
        analogWrite(EN , 0);
        
        dflg = true;
        //Serial.println(dflg);
      
        }
      
}
