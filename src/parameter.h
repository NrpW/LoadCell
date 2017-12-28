#ifndef PARAMETER_H
#define PARAMETER_H

class parameter
{
    private:
    public:
        parameter();
        long BaudRate;
        void loadParameter();

        //== calibration
        float calibration_factor;
        float clb_weight;
        float scalingFactor;
        float error_tolerance_kg;
};

#endif // PARAMETER_H
