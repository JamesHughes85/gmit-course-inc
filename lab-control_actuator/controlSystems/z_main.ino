#define PIN_LED1 3
#define PIN_SENSOR A1
#define PIN_SERVO 9
# include<Servo.h>

servoActuator testServo(PIN_SERVO,50);

depthSensor depth = depthSensor(PIN_SENSOR );

Servo myservo;
int depthSensor = 0;
int val;

void setup() {
  myservo.attach (9);
Serial.begin(9600);//open the serial port at 9600 bps:
}

void loop() {
  val = analogRead(depthSensor);
  val = map(val,0,1023,0,180);
  myservo.write(val);
  delay(200);
  
  depth.check();
  Serial.print(depth.getValue());
  Serial.print("\n ");
}
