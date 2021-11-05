#pragma once

#include <functional>
#include <vector>
#include <math.h>

class Function{
    public:
        virtual float get_y_at_x(float x) = 0;
        virtual std::vector<float> get_discontinuity_points() = 0;
        virtual void update( float x0, float y0 ) = 0;
    private:
        std::vector<float> discontinuity_points;
        float C;
        float x0;
        float y0;
};
