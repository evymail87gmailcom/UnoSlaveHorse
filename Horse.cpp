#include"Horse.h"
#include <iostream>
using namespace std;
void Horse::walk(int b) {

	Servo frontlegRight, backlegRight, frontlegLeft, backlegLeft;
	int pos = 0;
	
	Serial.println("backlegattached");
	delay(3000);
	if (b != 0) {

		Serial.println("Running function");
		
		backlegRight.attach(5);
		
		for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
												// in steps of 1 degree
			backlegRight.write(pos);              // tell servo to go to position in variable 'pos'
			delay(15);                       // waits 15ms for the servo to reach the position
		}
		delay(30);
		for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
			backlegRight.write(pos);              // tell servo to go to position in variable 'pos'
			delay(15);                       // waits 15ms for the servo to reach the position
		}
		
		Serial.println("BacklegRight moved!!");
		Serial.println("Leg is detached!");
		backlegRight.detach();
		delay(30);

		frontlegRight.attach(10);
		
		for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
												// in steps of 1 degree
			frontlegRight.write(pos);              // tell servo to go to position in variable 'pos'
			delay(15);                       // waits 15ms for the servo to reach the position
		}
		delay(30);
		for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
			frontlegRight.write(pos);              // tell servo to go to position in variable 'pos'
			delay(15);                       // waits 15ms for the servo to reach the position
		}
		
		Serial.println("FrontlegRight moved!!");
		Serial.println("Leg is detached!");
		frontlegRight.detach();
		delay(30);

		backlegLeft.attach(6);
		
		for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
												// in steps of 1 degree
			backlegLeft.write(pos);              // tell servo to go to position in variable 'pos'
			delay(15);                       // waits 15ms for the servo to reach the position
		}
		delay(30);
		for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
			backlegLeft.write(pos);              // tell servo to go to position in variable 'pos'
			delay(15);                       // waits 15ms for the servo to reach the position
		}
		
		Serial.println("BacklegLeft moved!!");
		Serial.println("Leg is detached!");
		backlegLeft.detach();
		delay(30);

		frontlegLeft.attach(9);
		
		for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
												// in steps of 1 degree
			frontlegLeft.write(pos);              // tell servo to go to position in variable 'pos'
			delay(15);                       // waits 15ms for the servo to reach the position
		}
		delay(30);
		for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
			frontlegLeft.write(pos);              // tell servo to go to position in variable 'pos'
			delay(15);                       // waits 15ms for the servo to reach the position
		}
		
		Serial.println("FrontLegLeft moved!!");
		Serial.println("Leg is detached!");
		frontlegLeft.detach();
		delay(300);
		countSteps++;

	}
	else {
		Serial.println("No steps were taken ");
	}

	}

int Horse::getSteps() {
	return countSteps;
}
void Horse::see() {
	
	NewPing see(12, 13, 200);
	distance = see.ping_cm();

}
int Horse::getDistancetoObject() {
	return distance;
}

void Horse::hear() {
	short rightSound;
	short leftSound;
	int rightSensorValue;
	int leftSensorValue;
	rightSound = 8;
	rightSensorValue = 0;

	leftSound = 7;
	leftSensorValue = 0;

	pinMode(rightSound, INPUT);
	pinMode(leftSound, INPUT);

	rightSensorValue = digitalRead(rightSound);
	leftSensorValue = digitalRead(leftSound);
	if ((rightSensorValue == leftSensorValue) && (rightSensorValue > 0)) {
		soundLevel = 1;
	}
	else soundLevel = 0;
}
int Horse::getSoundLevel() {
	return soundLevel;
}

void Horse::smell() {

	int smoke = A3;
	// Your threshold value
	int gasThres = 400;

	pinMode(smoke, INPUT);
	gasSensorValues = analogRead(smoke);
	delay(100);
}
int Horse::getGasValues() {
	return gasSensorValues;
}



void Horse::roam() {
	
	see();
	delay(100);
	hear();
	delay(100);
	smell();
	delay(100);

	Serial.print("distance: ");
	Serial.println(getDistancetoObject());

	//Uncomment these Serialprints for debugging
	Serial.print("stepcount: ");
	Serial.println(getSteps());

	//Uncomment these Serialprints for debugging
	Serial.print("SoundLevel: ");
	Serial.println(getSoundLevel());

	//Uncomment these Serialprints for debugging
	Serial.print("BlinkCount: ");
	Serial.println(getBlinkCount());

	//Uncomment these Serialprints for debugging
	Serial.print("Gasvalues: ");
	Serial.println(getGasValues());
	
}

void Horse::blinkTest(int a) {
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, a);
	if (a == 1) {
		blinkCount++;
	}
}
int Horse::getBlinkCount() {
	return blinkCount;
}
void Horse::doStuff(char a, int b) {
	
	if (a == '0') {
		blinkTest(b);
		delay(100);
	}
	if (a == '1') {
		walk(b);
		delay(100);
	}
}

void Horse::sendStuff() {
	vector<char>send;
	char type;
	
	type = char(getDistancetoObject());
	send.push_back(type);
	send.push_back(',');
	
	type = char(getSteps());
	send.push_back(type);
	send.push_back(',');
	
	type = char(getSoundLevel());
	send.push_back(type);
	send.push_back(',');

	type = char(getBlinkCount());
	send.push_back(type);
	send.push_back(',');
	
	type = char(getGasValues());
	send.push_back(type);
	send.push_back(',');

	for (int i = 0; i <= send.size(); i++)
	{
		Wire.write(send[i]);
		Serial.print("Sent value: ");
		Serial.println(i);
	}
	
}