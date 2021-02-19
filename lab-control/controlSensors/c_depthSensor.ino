
class depthSensor { // CLASS DEFINITION
 private:
  byte pinID;


  public:
  depthSensor(byte pinVal, unsigned long interval) {
  this->pinID = pinVal;  
  
     

   pinMode(pinID, OUTPUT);
    }

   
      
    
};
