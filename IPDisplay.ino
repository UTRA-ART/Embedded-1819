#include <LiquidCrystal.h>
#define rs 12
#define en 11
#define d4 5
#define d5 4
#define d6 3
#define d7 2
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  Serial.begin(9600); //Sets the baud rate 
  lcd.begin(16,2); //Sets number of displayed columns to 16 and the number of rows to 2
  lcd.clear(); //Clears the display of the LCD  
}

void loop() {
  char incoming_byte; //variable for storing the data coming from Jetson
  int i = 1;
  while(Serial.available() > 0){
    if (i==1){
      lcd.setCursor(0,0); //Starts the cursor at 0th column and 0th row
      lcd.clear();
    }
    incoming_byte = Serial.read();
    lcd.print(incoming_byte);
    lcd.setCursor(i,0);
    i++;
  }
  delay(30);
}
