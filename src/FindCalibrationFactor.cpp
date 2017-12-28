/*
== v0.1
code from aguegu
== v0.2
use parameter class
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "HX711.h"
#include <Wire.h>

#include "allHeader.h"
#include "parameter.h"
#define NUM_DECIMAL_POINT  2  // didn't use anymore

extern HX711 scale;
extern parameter prmt;
extern float calibration_factor;
//extern float clb_weight;
//extern float scalingFactor;


void FindCalibrationFactor(){
    //unsigned char flag_stable=0;
    unsigned int decpoint=1;    // What is decpoint? I think it is multiplication factor to make read_weight integer.
    for(unsigned char i=0;i<NUM_DECIMAL_POINT+1;i++ )
        decpoint = decpoint*10;

    float xx1=calibration_factor;
    xx1 = 18500000;
    float yy1;


    int ii=0;
    //double clb_weight = prmt.clb_weight;
    float clb_weight = prmt.clb_weight;
    float scalingFactor = prmt.scalingFactor;
    Serial.print("clb_weight = ");
    Serial.println(clb_weight);


    scale.set_scale(xx1);
    yy1 = (get_units_kg() - clb_weight)*scalingFactor + xx1; //it still require adjustment parameter
    Serial.println("xx1 \t scaledKg \t calibrationWeight \t yy1");
    print1(xx1,yy1);

    float ddd=444; // ddd is temporary variable to store difference between readValue and clbValue
    //some unknown problem about ddd
    double clb_weight_double = 0.20;
    double ddd_double = 444;

    while(1){
        ii++;
        xx1 = yy1;
        scale.set_scale(xx1);
        yy1 = (get_units_kg() - clb_weight)*scalingFactor + xx1;
        print1(xx1,yy1);
        delay(1000);
        ddd = (get_units_kg() - clb_weight);
        ddd_double = (get_units_kg() - clb_weight_double);
//        float temp_ddd = (get_units_kg() - clb_weight); //Thongou suggestion
//        ddd =  ddd> 0 ? ddd : ddd*-1 ;
        Serial.print( get_units_kg() );
        Serial.print("\t");
        Serial.print(clb_weight);
        Serial.print("\t");
        Serial.print( get_units_kg() - 0.20 );
        Serial.print("\t");
        Serial.print(ddd);
        Serial.print("\t");
        Serial.print( sqrt(pow(ddd,2)) ); //Holy duck. Why abs() function does not work? Then, I need to use this round about method.
        Serial.print("\t");
        Serial.print( ddd_double );
        Serial.print("\t");
        Serial.println();

        if ( sqrt(pow(ddd,2)) <= 0.005 ){
            calibration_factor = xx1;
            Serial.print("completed");
            Serial.print(" calibration_factor: ");
            Serial.print(xx1);
            Serial.println();
            break;
        }
        else if(ii>20){
            Serial.println("Error: not converge");
            break;
        }
    }

}
