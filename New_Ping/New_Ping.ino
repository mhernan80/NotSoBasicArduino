#include "Arduino.h"
#include <NewPing.h>

int maxd = 500;
int trig = 12;
int echo = 11;
int val = 0;
NewPing sonar(trig, echo, maxd);//trigger, echo, maximum distance

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	Serial.print("distance:");
	Serial.print(sonar.ping_cm());
	Serial.println(" cm");
	if(sonar.ping_cm()>=0)//makes sure that the distance number is valid (distances of less than zero are impossible)
	{
	
	analogWrite(5, map(sonar.ping_cm(),0,500,0,255));//maps the value so that the distance, which is normally between 0 and 500, becomes a number usable by the LED
	}
delay(20);
}

