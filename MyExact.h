#pragma once

#include "Exact.h"
#include <vector>
#include <math.h>

class MyExact : Exact{
    public:
        vector<Point> get_points(float x0, float y0, float X, int N);
    private:
        float get_y_at_x(float x, float x0, float y0);
        vector<float> discontinuity_points;
};
