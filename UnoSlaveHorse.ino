
#include "Horse.h"
//#include <Wire.h>
Horse myHorse;

static char zero = '0';
static char one = '0';
static int two = 0;
const int period1 = 10000;
unsigned long currentTime1 = 0;

const int period2 = 5000;
unsigned long currentTime2 = 0;

void setup() {
	
	Wire.begin(8);
	// join i2c bus with address #8
	Wire.onReceive(receiveEvent);
	// register event
	Wire.onRequest(requestEvent);
	Serial.begin(9600);	
	
}

void loop() {

	if (period2 + currentTime2 <= millis()) {
		myHorse.doStuff(one, two);
		currentTime2 = millis();
	}

	if (period1 + currentTime1 <= millis()) {
		myHorse.roam();
		currentTime1 = millis();
	}

}


void receiveEvent(int howMany) {
	int i = 0;
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
	


}

// Function that executes whenever data is requested by master
void requestEvent() {
	myHorse.sendStuff();
	//Wire.write(myHorse.getDistancetoObject());  
	

	//Wire.write(myHorse.getSteps());
	
	
	//Wire.write(myHorse.getSoundLevel());
	
	
	//Wire.write(myHorse.getBlinkCount());
	
	//Wire.write(myHorse.getGasValues());
	

}
