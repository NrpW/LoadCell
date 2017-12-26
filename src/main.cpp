#include "HX711.h"
#include <Wire.h>
#include "allHeader.h"

#define DOUT  A3
#define CLK   A2

#define NUM_DECIMAL_POINT  2
#define STABLE  1

float offset=0;
float calibration_factor = 1;
float clb_weight = 0.60;//kg

HX711 scale(DOUT, CLK);

unsigned char state=0;

void print1(float xx1, float yy);

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("Auto Calibrate Program");
  Serial.println("Send 'a' to Find Zero Factor (Please Remove all weight from scale)");
  Serial.println("Send 'b' to Find Calibration Factor (Please insert know the weight on the scales)");
  Serial.println("Send 'c' Show weight on the scales");
}
void loop()
{
  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp=='a')
      state=1;
    if(temp=='b')
      state=2;
    if(temp=='c')
      state=3;
  }

  switch(state)
  {
    case 0:
    break;
    case 1:
      FindZeroFactor();
   //   ReadWeight();
      state=0;
    break;
    case 2:
     FindCalibrationFactor();
     state=0;
    break;
    case 3:
      ReadWeight();
      delay(50);
    break;
    case 4:

    break;

  }
}




/*
 * Nsw
 * I modify calibration process because it took too long.
*/
float scalingFactor=1e6;
