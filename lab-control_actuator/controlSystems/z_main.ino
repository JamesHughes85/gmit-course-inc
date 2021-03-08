// JAMES HUGHES - INSTRUMENTATION AND CONTROL - LAB 5

#define PIN_SENSOR A1 //ANALOGUE PIN ASSIGNED TO THE DEPTHSENSOR
#define PIN_SERVO 9 //DIGITAL PIN ASSIGNED TO THE SERVO

depthSensor depth = depthSensor(PIN_SENSOR,1000);
servoActuator ServMo = servoActuator (PIN_SERVO,1);

int depthSensor = 0;
int val;

void setup() {
Serial.begin(9600);//START SERIAL PORT AT 9600 BAUD RATE:
}

void loop() {
  depth.DataConvert();
  Serial.print("Voltage :"); Serial.print(depth.getvoltage());
  Serial.println(" ");Serial.print("Analog reading :");Serial.print(depth.getsensorValue()); Serial.print(" ");
  //calls servo motor control using depth sensor values
  ServMo.ServoAngle(depth.getsensorValue());
}
