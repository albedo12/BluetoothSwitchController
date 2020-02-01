#include<SoftwareSerial.h>
#include <Servo.h>
#define TxD 11
#define RxD 13
Servo myservo;
SoftwareSerial bluetoothSerial(TxD, RxD);
int c;
int count=1;
int total=0;
long int reversedNumber=0;
int remainder;
void setup() {
  bluetoothSerial.begin(38400);
  Serial.begin(9600);
  myservo.attach(10);
  }

void loop(){
  myservo.write(0);
  if(bluetoothSerial.available()){
    int inChar = bluetoothSerial.read();
    //Serial.println(inChar);
    if(inChar!=97){
     if(isDigit(inChar)){
       inChar=inChar-48;
       total=inChar*count+total;
       count=count*10;
       Serial.println(total);
     }
    }
    //Here we have to reverse the number we have got.
   
    if(inChar==97){
      while(total != 0)
      {
        remainder = total%10;
        reversedNumber = reversedNumber*10 + remainder;
        total /= 10;
      }
      reversedNumber=reversedNumber*1000;
      Serial.println("delay:");
      Serial.println(reversedNumber);
      if(reversedNumber>0){
        delay(reversedNumber);
        myservo.write(60); 
        delay(1000);
        reversedNumber=0;
        total=0;
        inChar=0;
        count=1;
        remainder=0;
      }
    }

    else if(inChar==98){
      while(total != 0)
      {
        remainder = total%10;
        reversedNumber = reversedNumber*10 + remainder;
        total /= 10;
      }
      reversedNumber=reversedNumber*60000;
      Serial.println("delay:");
      Serial.println(reversedNumber);
      if(reversedNumber>0){
        delay(reversedNumber);
        myservo.write(60); 
        delay(1000);
        reversedNumber=0;
        total=0;
        inChar=0;
        count=1;
        remainder=0;
      }
    }

     else if(inChar==99){
      while(total != 0)
      {
        remainder = total%10;
        reversedNumber = reversedNumber*10 + remainder;
        total /= 10;
      }
      reversedNumber=reversedNumber*2400000;
      Serial.println("delay:");
      Serial.println(reversedNumber);
      if(reversedNumber>0){
        delay(reversedNumber);
        myservo.write(60); 
        delay(1000);
        reversedNumber=0;
        total=0;
        inChar=0;
        count=1;
        remainder=0;
      }
    }

   
 }
}
