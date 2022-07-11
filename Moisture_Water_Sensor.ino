#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
#define waterSensorPin A0
double waterBit, waterVoltage, waterPercentage;


void setup() 
{
  // put your setup code here, to run once:
  pinMode(waterSensorPin,INPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
  Serial.println("Made in Nigeria by JaeTech");
  delay(3000);
}

void loop() 
// put your main code here, to run repeatedly:
{
  waterBit = analogRead(waterSensorPin);
  waterVoltage = (waterBit*5)/1023;
  waterPercentage = (waterVoltage*100)/5;
  Serial.print("Moisture Percentage = ");
  Serial.print(waterPercentage);
  Serial.println("%");
  delay(1000);

  printReadings();
  

}
void printReadings()
{
  lcd.setCursor(0,0);
  lcd.print("Water Percent: ");
  lcd.setCursor(0,1);
  lcd.print(waterPercentage);
  lcd.print("%");
  delay(1000);
  lcd.clear();
}
