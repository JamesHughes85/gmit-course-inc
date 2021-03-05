class depthSensor {
  private:
    byte pinSensor;
    unsigned long nextChangeTime = 0;
   int val = 0 ;                           //variable to store the value read
float distance ;
  public:
      depthSensor(byte pinSensor) {
      this-> pinSensor = pinSensor;
     
pinMode (pinSensor, INPUT);               //Depth sensor is an input
    }


void calculate() {                              // the loop routine runs over and over
int sensorValue = analogRead(pinSensor);
 float voltage = sensorValue * (5.0 / 1023.0);
  distance =-22.469*voltage+60.131;   // Distance on the graph in cm
 
}
float getValue(){
  return distance;
}
       // Checks whether it is time to turn on or off the LED.
    void check() {
      unsigned long currentTime = millis();

      if(currentTime >= nextChangeTime) {
        calculate();
       
          nextChangeTime = currentTime + 20;
        }
    }
};
