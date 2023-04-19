#include<NewPing.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27,16,2);

#define trigPin 9
#define echoPin 10
  int LED1=2; 
  int LED2=3;
  int LED3=4;
  int LED4=5;
  int motor=6;


void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(motor,OUTPUT);
  
 lcd.begin();
 lcd.backlight();
 lcd.setCursor(0,0);
 lcd.print("Project By");
 lcd.setCursor(0,1);
 lcd.print(" Justclick Team");
 delay(2000);
 lcd.clear();
}

void loop() {
  int duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration /58;
  Serial.println(distance);
  lcd.setCursor(0,0);
  //lcd.print(distance);

  if(distance >=15 && distance <=50)
  {
    
    digitalWrite(motor,HIGH);
    lcd.setCursor(0,1);
    lcd.print("Motor is ON");
    delay(500);
    lcd.clear();
    if(distance<=50)
    {
      digitalWrite(LED1,HIGH);
      lcd.setCursor(0,0);
      lcd.print("Water Level 25%");
      //delay(500);
      //lcd.clear();
    }
    else 
    {
      digitalWrite(LED1,LOW);
    }
      if(distance<=35)
    {
      digitalWrite(LED2,HIGH);
       lcd.setCursor(0,0);
      lcd.print("Water Level 50%");
      //delay(500);
      //lcd.clear();
    }
    else
    {
      digitalWrite(LED2,LOW);
    }
      if(distance<=25)
    {
      digitalWrite(LED3,HIGH);
       lcd.setCursor(0,0);
      lcd.print("Water Level 75%");
      //delay(500);
      //lcd.clear();
    }
    else
    {
      digitalWrite(LED3,LOW);
    }
      if(distance<=15)
    {
      digitalWrite(LED4,HIGH);
       lcd.setCursor(0,0);
      lcd.print("Water Level 100%");
      //.delay(500);
      //lcd.clear();
    }
    else
    {
      digitalWrite(LED4,LOW);
    }
 
  }
  else
  {
    digitalWrite(motor,LOW);
    lcd.setCursor(0,1);
    lcd.print("Motor is OFF");
    delay(500);
    lcd.clear();
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(LED4,LOW);
  }
  delay(500);

}
