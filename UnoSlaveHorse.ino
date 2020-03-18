
#include "Horse.h"
#include<Wire.h>

Horse myHorse;

void setup() {
	Wire.begin(8);
	// join i2c bus with address #8
	Wire.onReceive(receiveEvent);
	// register event
	Wire.onRequest(requestEvent); 
	Serial.begin(9600);	
}

void loop() {

	delay(100);
}


void receiveEvent(int howMany) {
	int i = 0;
	char zero,one;
	int two;
	//When a command from the app is sent through the wire it will do so, sign by sign. 
	//In this case we always send three signs: V, 0 or 1 and finally 0 or 1. 
	//They all represent the same things, "wich virtualpin is the command from?" and "is it high or low?".
	while(Wire.available()) {
		switch (i)
		{
			//Every time the loop is run it will store the incoming values as the same datatypes they were sent 
		case 0: {
			zero = Wire.read();
			i++;
			break;
			}
		case 1: {
			one = Wire.read();
			i++;
			break;
		}
		case 2: {
			two = Wire.read();
			i++;
			break;
		}
		default:
			break;
		}
	
	}
	//If the virtualpin is 0 then it will run the blinktest as intended, otherwise it will run the walk-function
	if (one == '0') {
		myHorse.blinkTest(two);
	}
	else {
		myHorse.walk(two);
	}
	//Serialprints for debugging
	Serial.print("Zero: ");
	Serial.print(zero);
	Serial.print(", ");

	Serial.print("One: ");
	Serial.print(one);
	Serial.print(", ");

	Serial.print("Two: ");
	Serial.print(two);
	Serial.println(" ");
	Serial.println();
}
// Function that executes whenever data is requested by master

void requestEvent() {
	//Executes sensor-functions to collect data
	myHorse.roam();
	
	//Sends the collected data in a specific order
	Wire.write(myHorse.getDistancetoObject());  
	Serial.print("distance: ");
	Serial.println(myHorse.getDistancetoObject());
	
	Wire.write(myHorse.getSteps());
	Serial.print("stepcount: ");
	Serial.println(myHorse.getSteps());
	
	Wire.write(myHorse.getSoundLevel());
	Serial.print("SoundLevel: ");
	Serial.println(myHorse.getSoundLevel());

	Wire.write(myHorse.getBlinkCount());
	Serial.print("BlinkCount: ");
	Serial.println(myHorse.getBlinkCount());
	
	Wire.write(myHorse.getGasValues());
	Serial.print("Gasvalues: ");
	Serial.println(myHorse.getGasValues());
	
}