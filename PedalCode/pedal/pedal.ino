#include <Arduino.h>
#include <BleGamepad.h>
#include "List.h"
#include "Pedal.h"


#define CalibrateButton 31

int MIN_AXES = 0;
int MAX_AXES = 32000;


//because this is simple it only needs 3 axis,

Pedal Accelerator(13,0,1023,MIN_AXES,MAX_AXES);
Pedal Clutch(12,0,1023,MIN_AXES,MAX_AXES);;
Pedal Brake(14,0,1023,MIN_AXES,MAX_AXES);;


BleGamepad gamePad;
BleGamepadConfiguration config;

// put function declarations here:
void setup()
{
    Serial.begin(9600);
    gamePad.begin();
    gamePad.setAxes();  
}



void loop()
{
    delay(10);
    if(gamePad.isConnected())
    {
        Accelerator.readAndMap();
        Clutch.readAndMap();
        Brake.readAndMap();
      gamePad.setAxes(0,0,0,Accelerator.getAverage(),Brake.getAverage(),Clutch.getAverage());
      gamePad.sendReport();
    }
}








