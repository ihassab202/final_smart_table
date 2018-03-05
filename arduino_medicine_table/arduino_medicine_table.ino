//arduino of medicine drawers
//connect one to gnd of 4,5
#include<Servo.h>
Servo ser1;
Servo ser2;
Servo ser3;
boolean flag;
void setup() {
  
 ser1.attach(10);
 ser2.attach(11);
 ser3.attach(12);
pinMode(2,INPUT_PULLUP);//close
pinMode(3,INPUT_PULLUP);//open
pinMode(4,INPUT_PULLUP);//drawer 1
pinMode(5,INPUT_PULLUP);//drawer 3

}

void loop() {


      if(digitalRead(4)==0){
              if(digitalRead(2)==0){ser1.write();}//enter close number
              if(digitalRead(3)==0){ser1.write();}//enter open number
       }
       if(digitalRead(4)==1 && digitalRead(5)==1){
              if(digitalRead(2)==0){ser2.write();}//enter close number
              if(digitalRead(3)==0){ser3.write();}//enter open number
       }

       if(digitalRead(5)==0){
              if(digitalRead(2)==0){ser3.write();}//enter close number
              if(digitalRead(3)==0){ser3.write();}//enter open number
       }
      
}
