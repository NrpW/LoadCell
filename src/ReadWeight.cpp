#include "HX711.h"
#include <Wire.h>

#include "allHeader.h"

#define NUM_DECIMAL_POINT  2

extern HX711 scale;
extern float calibration_factor;
extern float offset;


void ReadWeight()
{
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  Serial.print("Reading: ");
  String data = String(get_units_kg()+offset, NUM_DECIMAL_POINT);
  Serial.print(data);
  Serial.println(" kg");
}
