#include"Horse.h"

void Horse::walk(int b) {
	Servo frontlegRight;
	Servo backlegRight;
	Servo frontlegLeft;
	Servo backlegLeft;
	short i, j, k, l;
	i = 0;
	j = 0;
	k = 0;
	l = 0;
	int a = 0;
	a = b;
	//countSteps = 0;
	//Defines pins used by servos
	//frontlegLeft.attach(9);
	//frontlegRight.attach(10);
	//backlegLeft.attach(6);
	backlegRight.attach(5);
	int middle = 90;
	int endPoint = 80;
	int stepDelay = 400;
	int pos = 0;

	if (a == 1) {
		//Test 1
		

		backlegRight.write(0);
		delay(30);
		backlegRight.write(2);
		delay(30);
		backlegRight.write(4);
		delay(30);
		backlegRight.write(6);
		delay(30);
		backlegRight.write(8);
		delay(30);
		backlegRight.write(10);
		delay(30);
		backlegRight.write(12);
		delay(30);
		backlegRight.write(14);
		delay(30);
		backlegRight.write(16);
		delay(30);
		backlegRight.write(18);
		delay(30);
		backlegRight.write(20);
		delay(30);
		backlegRight.write(22);
		delay(30);
		backlegRight.write(24);
		delay(30);
		backlegRight.write(26);
		delay(30);
		backlegRight.write(28);
		delay(30);
		backlegRight.write(30);
		delay(30);
		backlegRight.write(32);
		delay(30);
		backlegRight.write(34);
		delay(30);
		backlegRight.write(36);
		delay(30);
		backlegRight.write(38);
		delay(30);
		backlegRight.write(40);
		delay(30);
		backlegRight.write(42);
		delay(30);
		backlegRight.write(44);
		delay(30);
		backlegRight.write(46);
		delay(30);
		backlegRight.write(48);
		delay(30);
		backlegRight.write(50);
		delay(30);
		backlegRight.write(52);
		delay(30);
		backlegRight.write(54);
		delay(30);
		backlegRight.write(56);
		delay(30);
		backlegRight.write(58);
		delay(30);
		backlegRight.write(60);
		delay(30);

		

		/*
		//Test 2
		for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  // in steps of 1 degree
			backlegRight.write(pos);              // tell servo to go to position in variable 'pos'
			delay(15);                       // waits 15ms for the servo to reach the position
		}
		for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
			backlegRight.write(pos);              // tell servo to go to position in variable 'pos'
			delay(15);                       // waits 15ms for the servo to reach the position
		}
		*/
		//Test 3
		/*

		frontlegLeft.write(middle);
		backlegLeft.write(middle);
		frontlegRight.write(middle);
		backlegRight.write(middle);
		delay(stepDelay);

		frontlegLeft.write(middle - endPoint);
		delay(stepDelay);
		frontlegRight.write(middle + endPoint);
		delay(stepDelay);
		backlegLeft.write(middle - endPoint);
		delay(stepDelay);
		backlegRight.write(middle + endPoint);
		delay(stepDelay);
		*/

		/*
		//Test 4
		frontlegLeft.write(0);
		frontlegLeft.write(50);
		frontlegLeft.write(0);

		backlegRight.write(0);
		backlegRight.write(50);
		backlegRight.write(0);

		frontlegRight.write(0);
		frontlegRight.write(50);
		frontlegRight.write(0);

		backlegLeft.write(0);
		backlegLeft.write(50);
		backlegLeft.write(0);

		*/

		/*
		//Test 5
		// Back leg right
		for (i = 90; i >= 45; i - 2) {
			backlegRight.write(i);
			delay(150);
			frontlegLeft.write(i);
			delay(50);
		}

		for (k = i; k <= 90; k + 2)
		{

			backlegLeft.write(k);
			delay(50);
			frontlegRight.write(k);
			delay(50);
		}


		for (j = i; j <= 90; j + 2) {
			backlegRight.write(j);
			delay(50);
			frontlegLeft.write(j);
			delay(50);
		}

		for (l = j; l >= 30; l - 2)
		{

			backlegLeft.write(l);
			delay(50);
			frontlegRight.write(l);
			delay(50);
		}
		*/
		countSteps++;
	
	}

		a = 0;
		//frontlegLeft.detach();
		//frontlegRight.detach();
		//backlegLeft.detach();
		//backlegRight.detach();
	
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
	hear();
	smell();
	
}

void Horse::blinkTest(int a) {
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, a);
	blinkCount++;
}
int Horse::getBlinkCount() {
	return blinkCount;
}