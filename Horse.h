#pragma once
#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
class Horse {
public:
	Servo frontlegRight;
	Servo backlegRight;
	Servo frontlegLeft;
	Servo backlegLeft;

	// defines pins numbers
	short trigPin;
	short echoPin;
	// defines variables
	long duration;
	short distance;
	int countSteps;
	//Define soundsensors
	short analogRightSound;
	short analogLeftSound;
	short digitalRightSound;
	short digitalLeftSound;
	short rightSound;
	short leftSound;
	short soundlevel;
	int rightSensorValue;
	int leftSensorValue;
	int smoke;
	int gasThres;
	int gasSensorValues;
	int blinkCount=0;
	Horse() {};
	void walk(int b);
	void see();
	void hear();
	void smell();
	void stop();
	void roam();
	int getSteps();
	int getDistancetoObject();
	int getSoundLevel();
	int getGasValues();
	void blinkTest(int a);
	int getBlinkCount();
	~Horse() {};
};