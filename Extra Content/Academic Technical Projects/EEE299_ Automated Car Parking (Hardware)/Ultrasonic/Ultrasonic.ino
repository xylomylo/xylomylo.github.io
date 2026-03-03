
long tmeduration;
int distance;

const int trigPin_entry=22;
const int echoPin_entry=23; 

const int trigPin_exit=48;
const int echoPin_exit=49;

void setup() 
              {
                
                pinMode(trigPin_entry,OUTPUT);
                pinMode(echoPin_entry,INPUT);
                Serial.begin(9600);
              }


void loop()
          {
            digitalWrite(trigPin_entry,LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin_entry,HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin_entry,LOW);

            tmeduration=pulseIn(echoPin_entry,HIGH);
            distance=(0.034*tmeduration)/2;
            
            Serial.print(distance);
            Serial.print(" centimetres ");
            Serial.println();
          }

       
