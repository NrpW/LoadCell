#include "HX711.h"
#include <Wire.h>

#include "allHeader.h"
#include "parameter.h"

extern HX711 scale;
extern parameter prmt;


void print1(float xx1, float yy1){
    Serial.print(xx1);
    Serial.print("\t");

    Serial.print(get_units_kg()*prmt.scalingFactor);
    Serial.print("\t");

    Serial.print(prmt.clb_weight * prmt.scalingFactor);
    Serial.print("\t");

    Serial.print(yy1);
    Serial.println();
}
