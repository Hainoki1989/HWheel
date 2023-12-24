#include <Arduino.h>
#include "List.h"

class Pedal {
private:
  int PIN_NUMBER;
  int POT_MIN;
  int POT_MAX;
  MyList<int, 4> values;
  int MIN_AXIS;
  int MAX_AXIS;

public:
  Pedal(int pin, int minVal, int maxVal, int minAxis, int maxAxis)
      : PIN_NUMBER(pin), POT_MIN(minVal), POT_MAX(maxVal), MIN_AXIS(minAxis), MAX_AXIS(maxAxis) {}

   void calibrate() {
    int sensorValue = analogRead(PIN_NUMBER);

    // Adjust POT_MIN if the read value is less than POT_MIN
    if (sensorValue < POT_MIN) {
      POT_MIN = sensorValue;
    }

    // Adjust POT_MAX if the read value is greater than POT_MAX
    if (sensorValue > POT_MAX) {
      POT_MAX = sensorValue;
    }
  }

  int readAndMap() {
    calibrate(); // Run calibration before reading and mapping

    int sensorValue = analogRead(PIN_NUMBER);
    int mappedValue = map(sensorValue, POT_MIN, POT_MAX, MIN_AXIS, MAX_AXIS);
    values.push(mappedValue);
    return mappedValue;
  }


  int getAverage() {
    int total = 0;
    for (int i = 0; i < values.count; i++) {
      total += values.pop();
    }
    return total / values.count;
  }
};