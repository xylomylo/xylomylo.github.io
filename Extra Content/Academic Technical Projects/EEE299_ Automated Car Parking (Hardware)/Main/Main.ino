
#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
// Wiring: SDA pin is connected to 20 and SCL pin to 21.
// Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,20,4) for 20x4 LCD.

void setup() {
  // put your setup code here, to run once:
  // Initiate the LCD:
  lcd.init();
  lcd.backlight();
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

}

void loop() {
  // put your main code here, to run repeatedly:
    lcd.setCursor(2, 0); // Set the cursor on the third column and first row.
    lcd.print("Questioning My"); // Print the string "Hello World!"
    lcd.setCursor(2, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
    lcd.print("Existence");

    myservo.write(60);              // tell servo to go to position in variable 'pos'
    delay(1525);    
    myservo.write(270); 
    delay(1525);  
}
