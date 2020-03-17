#include"Horse.h"

void Horse::walk(int b) {
	short i, j, k, l;
	i = 0;
	j = 0;
	k = 0;
	l = 0;
	int a = 0;
	a = b;
	//countSteps = 0;
	//Defines pins used by servos
	frontlegLeft.attach(9);
	frontlegRight.attach(10);
	backlegLeft.attach(6);
	backlegRight.attach(5);

	if (a == 1) {

		
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

		

		/*
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
		frontlegLeft.detach();
		frontlegRight.detach();
		backlegLeft.detach();
		backlegRight.detach();
	
	//countSteps++;
}

int Horse::getSteps() {
	return countSteps;
}
void Horse::see() {
	trigPin = 12;
	echoPin = 13;
	pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
	pinMode(echoPin, INPUT); // Sets the echoPin as an Input
	//Serial.begin(9600); // Starts the serial communication

		// Clears the trigPin
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(echoPin, HIGH);
	// Calculating the distance
	distance = duration * 0.034 / 2;
	// Prints the distance on the Serial Monitor
	//Serial.print("Distance: ");
	//Serial.println(distance);


}
int Horse::getDistancetoObject() {
	return distance;
}

void Horse::hear() {
	rightSound = 8;
	rightSensorValue = 0;

	leftSound = 7;
	leftSensorValue = 0;

	
	//Serial.begin(9600);
	pinMode(rightSound, INPUT);
	pinMode(leftSound, INPUT);


	rightSensorValue = digitalRead(rightSound);
	//Serial.print("RightSensorValue: ");
	//Serial.println(rightSensorValue);


	leftSensorValue = digitalRead(leftSound);
	//Serial.print("AnalogLeftSensorValue: ");
	//Serial.println(leftSensorValue);


}
int Horse::getSoundLevel() {
	if ((rightSensorValue == leftSensorValue)&&(rightSensorValue>0)) {
		return rightSensorValue;
	}
	else {
		return 0;
	};
}

void Horse::smell() {
	smoke = A3;
	// Your threshold value
	gasThres = 400;

	pinMode(smoke, INPUT);
	//Serial.begin(9600);

	gasSensorValues = analogRead(smoke);
	//Serial.print("Pin A3: ");
	//Serial.println(gasSensorValues);
	// Checks if it has reached the threshold value
	/*
	if (gasSensorValues > gasThres)
	{
		Serial.println("Check Air, and put yourself to safety!");
	}
	else
	{
		Serial.print("Smells good!");
	}
	*/
	delay(100);

}
int Horse::getGasValues() {
	//smell();
	return gasSensorValues;
	if (gasSensorValues > gasThres)
	{
		Serial.println("Check Air, and put yourself to safety!");
	}
	else
	{
		Serial.print("Smells good!");
	}
}

void Horse::stop() {
	if (distance == 20) {
		frontlegLeft.write(0);
		frontlegRight.write(0);
		backlegLeft.write(0);
		backlegRight.write(0);

		frontlegLeft.detach();
		frontlegRight.detach();
		backlegLeft.detach();
		backlegRight.detach();
	}
}

void Horse::roam() {
	
	see();
	hear();
	smell();
	
}

void Horse::blinkTest(int a) {
	pinMode(LED_BUILTIN, OUTPUT);
	//float c = Wire.read();
	//Serial.print(c);
	digitalWrite(LED_BUILTIN, a);
	blinkCount++;
}
int Horse::getBlinkCount() {
	return blinkCount;
}