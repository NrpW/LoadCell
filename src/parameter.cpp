//#include <iostream>
#include "allHeader.h"
#include "parameter.h"

using namespace std;

parameter::parameter()
{
    /* constructor */
    /* @improve   this will be loaded from a file. */
    BaudRate = 115200;
    clb_weight = 0.20; /* kg */
    calibration_factor = 762395.75;

    //==== FindCalibrationFactor
    //x0 = 500000
    scalingFactor=1e6;
    error_tolerance_kg = 0.005;
}
