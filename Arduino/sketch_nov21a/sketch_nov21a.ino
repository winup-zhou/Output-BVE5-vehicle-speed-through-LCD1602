char trainspeed = 0;
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200,SERIAL_8N1);
  lcd.init();  
  lcd.backlight();  
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {
    trainspeed = Serial.read();
    lcd.setCursor(0,0);
    lcd.print("Speed:");
    lcd.setCursor(8,0);
    lcd.print(trainspeed, DEC);
    }
}
