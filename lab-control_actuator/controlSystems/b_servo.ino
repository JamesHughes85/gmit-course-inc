 // JAMES HUGHES - INSTRUMENTATION AND CONTROL - LAB 5
 
 # include<Servo.h> //INCLUDE SERVO LIBRARY:
 
class servoActuator { //SERVO CLASS
  private:
  byte PIN_SERVO;
  unsigned long timeOn;
  Servo ServMo;
     
  public:
  servoActuator(byte PIN_SERVO,unsigned long timeOn){//CONSTUCTOR TAKES INPUTS FROM Z_MAIN AND APPLIES TO CLASS VARIABLES:
  pinMode(PIN_SERVO, OUTPUT);
  this->PIN_SERVO = PIN_SERVO;
  this->timeOn = timeOn;       
    }
void ServoAngle(int angle){ //THIS FUNCTION MAPS THE VOLTAGE OF THE OUTPUT TO THE ANGLE OF THE MOTOR
   ServMo.attach(PIN_SERVO);       
   angle = map(angle, 0, 1023, 0, 180);    
   ServMo.write(angle);                  
   delay(timeOn);
     }};
