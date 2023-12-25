
#include <Arduino.h>
#include <HID-Project.h>

const int numSwitches =5;
const int FirstAddSwitch = 9;
const int SecondAddSwitch = 10;

const int switchpins[] = {4,5,6,7,8};
byte previousValues = B11111;
byte AdditionalSwitches = 0;

void setup() 
{
  for(int i=0; i<numSwitches; i++)
  {
      pinMode(switchpins[i],INPUT_PULLUP);
  }

  pinMode(FirstAddSwitch,INPUT_PULLUP);
  pinMode(SecondAddSwitch,INPUT_PULLUP);
  
  Gamepad.begin();

}

void loop() 
{

  byte switchState = 0;

  int x = digitalRead(FirstAddSwitch);
  int y = digitalRead(SecondAddSwitch);

  bitWrite(AdditionalSwitches,0,x);
  bitWrite(AdditionalSwitches,1,y);

  for(int i=0; i<numSwitches;i++)
  {
    bitWrite(switchState,i,digitalRead(switchpins[i]));
  }

  if(switchState != previousValues)
  {
    for(int i=1; i<=7; i++)
    {
      Gamepad.release(i);
    }

    switch (switchState) {
      case B10010: Gamepad.press(1); break;
      case B10001: Gamepad.press(2); break;
      case B00010: Gamepad.press(3); break;
      case B00001: Gamepad.press(4); break;
      case B01010: Gamepad.press(5); break;
      case B01001: Gamepad.press(6); break;
      case B00110: Gamepad.press(7); break;
    }  
    previousValues = switchState;

  }

  Gamepad.release(8);
  Gamepad.release(9);

  if(bitRead(AdditionalSwitches,0) == 1)
    {
       Gamepad.press(8);
    }

    if(bitRead(AdditionalSwitches,1) == 1)
    {
        Gamepad.press(9);
    }

}
