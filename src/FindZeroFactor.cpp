#include "HX711.h"
#include <Wire.h>

#include "allHeader.h"

extern HX711 scale;

long FindZeroFactor()
{
     Serial.println("Find Zero Factor");
     Serial.println("Please wait .....");
     scale.set_scale();
     scale.tare();
     long zero_factor = scale.read_average(20);
     Serial.print("Zero factor: ");
     Serial.println(zero_factor);
     return(zero_factor);
}
