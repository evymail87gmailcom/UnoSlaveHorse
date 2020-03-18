#pragma once
#include <Arduino.h>
#include <Servo.h>
#include <NewPing.h>

class Horse {

protected:

	int distance;
	int countSteps;
	//Define soundsensors
	int soundLevel=0;
	int gasSensorValues;
	int blinkCount=0;
	void see();
	void hear();
	void smell();
public:
	Horse() {};
	void walk(int b);
	void roam();
	int getSteps();
	int getDistancetoObject();
	int getSoundLevel();
	int getGasValues();
	void blinkTest(int a);
	int getBlinkCount();
	~Horse() {};
};