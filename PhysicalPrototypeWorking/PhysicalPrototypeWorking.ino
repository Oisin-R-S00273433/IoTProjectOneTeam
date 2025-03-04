#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int LCD_COLUMNS = 16;
const int LCD_LINES = 4;
int ledPin = 7;
int sensorPin1 = 4;
int long ranDelay = 0;
int   sensorValue = 0;
float realTime;

void setup()
{

  lcd.begin(LCD_COLUMNS, LCD_LINES);
    lcd.setRGB(255, 255, 255);

  // Print something
  lcd.setCursor(3, 0);
  lcd.print("hellohellohelooo");
  lcd.setCursor(2, 1);
  lcd.print("");
  lcd.setCursor(5, 2);
  lcd.print("");
  lcd.setCursor(7, 3);
  lcd.print("");

  Serial.begin(9600);
   pinMode(ledPin, OUTPUT);
  pinMode(sensorPin1, INPUT);
}

void loop(){
   Serial.println("");
  Serial.println("");
  Serial.println("");
  lcd.setCursor(0, 0);
  lcd.println("Push the button");
  lcd.setCursor(0, 1);
  lcd.println("to start game");
  
  while (digitalRead(sensorPin1)==   0) {}

  Serial.println("");
  Serial.println("");
  Serial.println("");
  lcd.setCursor(0, 0);
  lcd.clear();


  lcd.setCursor(0, 0);
  lcd.println("Get Ready!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.println("Get Set!");
   delay(1000);
  ranDelay = random(5000);
  delay(ranDelay);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.println("Go!");
   
  realTime = millis();
  digitalWrite(ledPin, HIGH);
 
  
  while   (digitalRead(sensorPin1)== 0) {
    
  }
  digitalWrite(ledPin, LOW);
  lcd.clear();
   lcd.setCursor(0, 0);
   lcd.println("Time");
  realTime = millis()-realTime;
   lcd.setCursor(0, 1);
 lcd.println(realTime/1000,2);
 
   lcd.println(" Seconds");
 delay(2000); 
}



