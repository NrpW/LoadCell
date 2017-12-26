#include "HX711.h"
#include <Wire.h>

#include "allHeader.h"

extern HX711 scale;
extern float scalingFactor;
extern float clb_weight;

void print1(float xx1, float yy1){
    Serial.print(xx1);
    Serial.print("\t");

    Serial.print(get_units_kg()*scalingFactor);
    Serial.print("\t");

    Serial.print(clb_weight*scalingFactor);
    Serial.print("\t");

    Serial.print(yy1);
    Serial.println();
}
