#include "HX711.h"
#include <Wire.h>

#include "allHeader.h"
#define NUM_DECIMAL_POINT  2

extern HX711 scale;
extern float calibration_factor;
extern float clb_weight;
extern float scalingFactor;


void FindCalibrationFactor(){
    //unsigned char flag_stable=0;
    unsigned int decpoint=1;    // What is decpoint? I think it is multiplication factor to make read_weight integer.
    for(unsigned char i=0;i<NUM_DECIMAL_POINT+1;i++ )
        decpoint = decpoint*10;

    float xx1=calibration_factor;
    xx1 = 500000;
    float yy1;
    float arX[3] = {0,0,0};
    arX[0] = xx1;

    int ii=0;


    scale.set_scale(xx1);
    yy1 = (get_units_kg() - clb_weight)*scalingFactor + xx1; //it still require adjustment parameter
    Serial.println("xx1 \t scaledKg \t calibrationWeight \t yy1");
    print1(xx1,yy1);

    while(1){
        ii++;
        xx1 = yy1;
        scale.set_scale(xx1);
        yy1 = (get_units_kg() - clb_weight)*scalingFactor + xx1;
        print1(xx1,yy1);
        delay(1000);

        if (abs(get_units_kg() - clb_weight) <= 0.005){
            calibration_factor = xx1;
            Serial.print("completed");
            Serial.print(" calibration_factor: ");
            Serial.print(xx1);
            Serial.println();
            break;
        }
        else if(ii>20){
            Serial.println("Error: not converge");
        }
    }

}
