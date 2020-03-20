#pragma once

#include <Arduino.h>
#include <Servo.h>
#include <NewPing.h>
#include <Wire.h>


class Horse {

protected:


	int distance;
	int countSteps;
	//Define soundsensors
	int soundLevel=0;
	int gasSensorValues;
	int blinkCount=0;

public:
	
	Horse() {};
	void see();
	void hear();
	void smell();
	void walk(int b);
	void roam();
	int getSteps();
	int getDistancetoObject();
	int getSoundLevel();
	int getGasValues();
	void blinkTest(int a);
	int getBlinkCount();
	void doStuff(char a, int b);
	void sendStuff();
	
	~Horse() {};
};