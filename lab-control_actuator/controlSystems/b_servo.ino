 // JAMES HUGHES - INSTRUMENTATION AND CONTROL - LAB 5
 
 # include<Servo.h>
 
class servoActuator {

private:
  byte PIN_SERVO;
  unsigned long timeOn;
  Servo ServMo;
     
public:
  servoActuator(byte PIN_SERVO,unsigned long timeOn){
  pinMode(PIN_SERVO, OUTPUT);
  this->PIN_SERVO = PIN_SERVO;
  this->timeOn = timeOn;       
    }
void ServoAngle(int angle){
   ServMo.attach(PIN_SERVO);       
   angle = map(angle, 0, 1023, 0, 180);    
   ServMo.write(angle);                  
   delay(timeOn);
     }
 };
