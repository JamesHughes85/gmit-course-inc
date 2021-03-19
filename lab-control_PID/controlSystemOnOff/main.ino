//James Hughes - Instrumentation and Control Lab 6 - 19/03/21

#include <PID_v1.h>
double Setpoint, Input, Output;
double Kp=2, Ki=5, Kd=1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

int reading = 0;
int tempSensorPin = A0;
int relay =7;
float calibration = 0.1039;
float tempC; // Celcius

 void setup() {
 Input = analogRead(tempSensorPin);
 Setpoint = 100;
 myPID.SetMode(AUTOMATIC);
  
 Serial.begin(9600);
 pinMode(relay,OUTPUT);
 analogReference(INTERNAL);
}
void loop() {
 Input = analogRead(tempSensorPin);
 myPID.Compute();
 analogWrite(reading, Output);
 Serial.println(tempC);
  
  reading = analogRead(tempSensorPin);
  tempC = analogRead(tempSensorPin) * calibration; // get temp
  Serial.print("Temperature is  ");
  Serial.print(tempC, 1); // one decimal place resolution is all you get
  Serial.print(" Celcius  ");
  
  if (tempC <=35) {
  digitalWrite(7,HIGH);}
  else { digitalWrite(7,LOW);
}
delay(1000);
}
