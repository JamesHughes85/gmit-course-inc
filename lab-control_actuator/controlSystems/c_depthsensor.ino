// JAMES HUGHES - INSTRUMENTATION AND CONTROL - LAB 5

class depthSensor { //DEPTH SENSOR CLASS
  private:
  int Pin_Input;
  int Sample_Time;
  int sensorValue;
  float voltage;
  unsigned long nextChangeTime = 0;
  
  public:
  depthSensor(byte Pin_Input,int Sample_Time){//CONSTUCTOR TAKES INPUTS FROM Z_MAIN AND APPLIES TO CLASS VARIABLES:
  this->Pin_Input = Pin_Input;
  this->Sample_Time = Sample_Time;
   }

void DataConvert(){ //THIS FUNCTION CONVERTS ANALOG INPUT TO VOLTAGE OUTPUT: 
   unsigned long currentTime = millis();
    
    if(currentTime >= nextChangeTime) { //DATA OUTPUT SMOOTHING:
      
     this->sensorValue = analogRead(Pin_Input);//READ FROM ANALOGUE INPUT AND CONVERT TO VOLTAGE:
          
   this-> voltage = sensorValue * (5.0 / 1023.0);// CONVERTS ANALOGUE(0 - 1023) TO VOLTAGE (0 - 5V) AND STORE IN VARIABLE:
    nextChangeTime = currentTime + Sample_Time;
    }}
    float getvoltage(){//FUNCTION TO RETURN VOLTAGE TO Z_MAIN TO BE PRINTED
      return voltage;
    }
    int getsensorValue(){
      return sensorValue;
      delay(300);
    } };
