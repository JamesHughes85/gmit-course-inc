// JAMES HUGHES - INSTRUMENTATION AND CONTROL - LAB 5

#define PIN_SENSOR A1
#define PIN_SERVO 9

depthSensor depth = depthSensor(PIN_SENSOR,1000);
servoActuator ServMo = servoActuator (PIN_SERVO,1);


int depthSensor = 0;
int val;

void setup() {
Serial.begin(9600);//open the serial port at 9600 bps:
}

void loop() {
  depth.DataConvert();

//Prints out the resulting voltage and analog readings to the screen on the serial monitor
  Serial.print("Voltage :"); Serial.print(depth.getvoltage());
  Serial.println(" ");Serial.print("Analog reading :");Serial.print(depth.getsensorValue()); Serial.print(" ");
  //calls servo motor control using depth sensor values
  ServMo.ServoAngle(depth.getsensorValue());
}
