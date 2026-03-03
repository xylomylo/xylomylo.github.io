#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
                                                                                                                                   
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4); // SDA: Arduino 20, SCL: Arduino 21.                       
                                                                                                                                                                                                                                                              
Servo gate1,gate2;

float f=0.6; 
int close_gate=60, open_gate=270,s,i;
const int t[] = {30,32,22,24,26,28};                //Defining all Sonar Trigger Pins
const int e[] = {31,33,23,25,27,29};                //Defining all Sonar Echo Pins
long D[6];  
long data[6];   
long dur,dis;

boolean entry_state=false;
boolean exit_state=false;
boolean slot1_state=false;
boolean slot2_state=false;
boolean slot3_state=false;
boolean slot4_state=false;

long Entry=19*f;
long Exit=19*f;
long slot=9*f;
//unsigned long myTime;
int pass_time=1000;

void setup()
            {
              Serial.begin(9600);
              lcd.init();
              lcd.backlight();
              lcd.clear();
              gate1.attach(6);
              gate2.attach(7);
              
              for (int i=0; i<6; i++)
                                      {
                                        pinMode(t[i], OUTPUT);
                                        pinMode(e[i], INPUT);
                                      }
            
             }

void loop()
           {     
            //lcd.clear();
            lcd.setCursor(2, 0);
            lcd.print("SMART CAR PARKING");
            
            for (int i=0; i<6; i++)
                                   {
                                    data[i]=readSonar(i);
                                    Serial.print(data[i]);  
                                    
                                    Serial.print("    cm          ");                                 
                                   } 
            Serial.println();
            Serial.println();
            
            exit_state=state(0,Exit);
            Serial.print("Exit State:  ");
            Serial.print(exit_state);
            
            entry_state=state(1,Entry);
            Serial.print("    Entry State:  ");
            Serial.print(entry_state);
            
            slot1_state=state(2,slot);
            Serial.print("    S1 State:  ");
            Serial.print(slot1_state);
            
            slot2_state=state(3,slot);
            Serial.print("    S2 State:  ");
            Serial.print(slot2_state);
            
            slot3_state=state(4,slot);
            Serial.print("    S3 State:  ");
            Serial.print(slot3_state);
            
            slot4_state=state(5,slot);
            Serial.print("    S4 State:  ");
            Serial.println(slot4_state);
            
            s=4-(slot1_state+slot2_state+slot3_state+slot4_state);
            
            if (slot1_state==1) {lcd.setCursor(0, 1);lcd.print("S1:FULL ");}
       else if (slot1_state==0) {lcd.setCursor(0, 1);lcd.print("S1:EMPTY");}
            if (slot2_state==1) {lcd.setCursor(10,1);lcd.print("S2:FULL ");}
       else if (slot2_state==0) {lcd.setCursor(10,1);lcd.print("S2:EMPTY");}
            if (slot3_state==1) {lcd.setCursor(0,2); lcd.print("S3:FULL ");}
       else if (slot3_state==0) {lcd.setCursor(0,2); lcd.print("S3:EMPTY");}
            if (slot4_state==1) {lcd.setCursor(10,2);lcd.print("S4:FULL ");}
       else if (slot4_state==0) {lcd.setCursor(10,2);lcd.print("S4:EMPTY");}

            if (entry_state==1 || exit_state==1)
                                                {  //open gates           
                                                 if(entry_state==1){gate1.write(30);delay(pass_time);}
                                                 if(exit_state==1) {gate2.write(50);delay(pass_time);}
                                                }
            
       else if(entry_state==0 || exit_state==0)  
                                               {   //close gates          
                                                if(entry_state==0){gate1.write(120);delay(pass_time);}
                                                if(exit_state==0) {gate2.write(140);delay(pass_time);}
                                               }
            
           lcd.setCursor(1,3);
           lcd.print("Remaining Slots: "); 
           lcd.print(s);
           lcd.print(" ");
           
           
           }     
             
int readSonar(int i)
                    {
                      digitalWrite(t[i],LOW);
                      delayMicroseconds(2);
                      digitalWrite(t[i],HIGH);
                      delayMicroseconds(10);
                      digitalWrite(t[i],LOW);
          
                      dur=pulseIn(e[i],HIGH);
                      dis=((0.034*dur)/2);
                      return dis;
                    }

int state(int i,int j)
                      {
                        boolean state;
                        if(data[i]<=j)  {state=true;}
                        else if (data[i]>=j) {state=false;}
                        return state;
                      }
