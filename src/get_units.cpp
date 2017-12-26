#include "HX711.h"
#include <Wire.h>

#include "allHeader.h"

extern HX711 scale;


float get_units_kg()
{
  return(scale.get_units()*0.453592);
}
