#pragma once

#include "Function.h"

class MyFunction : public Function {
    public:
        MyFunction();
        float get_y_at_x(float x);
        std::vector<float> get_discontinuity_points();
        void update( float x0, float y0 );
    private:
        std::vector<float> discontinuity_points;
        float C;
        float x0;
        float y0;
};
