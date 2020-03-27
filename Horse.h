#pragma once

#include <Arduino.h>
#include <Servo.h>
#include <NewPing.h>
#include <Wire.h>


class Horse {

private:

	//Defines sensors that needs to be used in more than on function
	int distance;
	int countSteps;
	int soundLevel=0;
	int gasSensorValues;
	int blinkCount=0;
	void see();
	void hear();
	void smell();
	void walk(int b);
	int getSteps();
	int getDistancetoObject();
	int getSoundLevel();
	int getGasValues();
	void blinkTest(int a);
	int getBlinkCount();

public:

	Horse() {};	
	void roam();
	void blinkOrWalk(char a, int b);
	void sendSensorValues();
	~Horse() {};
};