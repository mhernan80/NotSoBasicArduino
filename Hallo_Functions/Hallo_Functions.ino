#include <Servo.h>

Servo myservo;//defines servo
int echo = 12;
int trig = 11;
int duration = 0;
int dur2 = 0;
void setup()
{

	Serial.begin(9600);
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
	myservo.attach(5);//attaches servo to pin 5
}

void loop()
{
 	pulse();
 	if(dur2 <= 5 && dur2 >=0)//checks that duration from trigger to echo is between zero and five
	 {
	 	myservo.write(95);
	 }
	 else if(dur2 <= 10 && dur2 >= 5)
	 {
	 	myservo.write(85);//moves servo opposite direction
	 }
	 else
	 {
	 	myservo.write(90);//stops servo
	 }
Serial.println(dur2);
delay(20);
}

void pulse()//pulse is the trigger to echo commands
{
	digitalWrite(trig, LOW);
	delay(5);
	digitalWrite(trig, HIGH);//turns on the sensor
	delay(10);
	digitalWrite(trig, LOW);

   duration = pulseIn(echo, HIGH);//finds time from trigger send to return
   dur2 = duration/2/29.1;//changes the value from seconds to cm
}

