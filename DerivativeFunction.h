#pragma once

#include <vector>
#include <algorithm>
#include <math.h>

class DerivativeFunction {
    public:
        DerivativeFunction();
        float get_value(float x, float y);
        void update( float x0, float y0 );
    private:
        float x0;
        float y0;
};
