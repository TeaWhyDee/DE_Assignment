#pragma once

#include <functional>
#include <vector>
#include <math.h>

class Function{
    public:
        Function( float (*f)(float x, float x0, float y0),
                std::vector<float>& points_of_discontinuity );

        float get_y_at_x(float x, float x0, float y0);
        std::vector<float> get_discontinuity_points();
    private:
        std::vector<float> discontinuity_points;
        std::function<float( float x, float x0, float y0 )> func;
};
