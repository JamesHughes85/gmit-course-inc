//James Hughes Instrumentation and Control Lab 4 19/02/21

#define PIN_LED 3
#define PIN_SENSOR A1
Blinker blink1 = Blinker(PIN_LED, 500, 500);
depthSensor;
float getValue;


void setup() {

 Serial.begin(9600);
}

void loop() {
  
  blink1.check(); 

  Serial.println(getValue);
  Serial.print (" ");
}
