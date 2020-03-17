/*
 Name:		UnoSlaveHorse.ino
 Created:	3/9/2020 1:53:36 PM
 Author:	Arman
*/

// the setup function runs once when you press reset or power the board
#include "Horse.h"
#include<Wire.h>

Horse myHorse;

int tabell[] = { 0,0 };
void setup() {
	
	
	//myHorse.roam();
	Wire.begin(8);
	// join i2c bus with address #8
	Wire.onReceive(receiveEvent);
	
	Wire.onRequest(requestEvent); // register event
	
	Serial.begin(9600);
	
}

// the loop function runs over and over again until power down or reset
void loop() {

	delay(100);
}


void receiveEvent(int howMany) {
	int i = 0;
	char zero;
	char one;
	int two;
	while(Wire.available()) {
		switch (i)
		{
		case 0: {
			zero = Wire.read();
			Serial.print("wire: ");
			Serial.print(zero);
			Serial.println(" ");
			Serial.print("i is: ");
			Serial.print(i);
			Serial.println(" ");
			i++;
			break;
			}
		case 1: {
			one = Wire.read();
			Serial.print("wire: ");
			Serial.print(one);
			Serial.println(" ");
			Serial.print("i is: ");
			Serial.print(i);
			Serial.println(" ");
			i++;
			break;
		}
		case 2: {
			two = Wire.read();
			Serial.print("wire: ");
			Serial.print(two);
			Serial.println(" ");
			Serial.print("i is: ");
			Serial.print(i);
			Serial.println(" ");
			i++;
			break;
		}
		default:
			break;
		}
	
		//myHorse.walk(b);

	
	}
	if (one == '0') {
		myHorse.blinkTest(two);
	}
	else {
		myHorse.walk(two);
	}
	Serial.print("Zero: ");
	Serial.print(zero);
	Serial.println(" ");

	Serial.print("One: ");
	Serial.print(one);
	Serial.println(" ");

	Serial.print("Two: ");
	Serial.print(two);
	Serial.println(" ");
	//count++;
	//Serial.print("counter: ");
	//Serial.println(count);
	//myHorse.blinkTest();

	Serial.println();
}
// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
	myHorse.roam();
	//myHorse.see();
	Wire.write(myHorse.getDistancetoObject());  
	Serial.print("distance: ");
	Serial.println(myHorse.getDistancetoObject());
	
	Wire.write(myHorse.getSteps());
	Serial.print("stepcount: ");
	Serial.println(myHorse.getSteps());
	//myHorse.hear();
	Wire.write(myHorse.getSoundLevel());
	Serial.print("SoundLevel: ");
	Serial.println(myHorse.getSoundLevel());
	Wire.write(myHorse.getBlinkCount());
	Serial.print("BlinkCount: ");
	Serial.println(myHorse.getBlinkCount());
	//myHorse.smell();
	Wire.write(myHorse.getGasValues());
	Serial.print("Gasvalues: ");
	Serial.println(myHorse.getGasValues());
	
}