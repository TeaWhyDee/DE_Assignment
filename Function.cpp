#pragma once

#include <vector>
#include <math.h>
#include "Function.h"

Function::Function( float (*f)(float x, float x0, float y0),
        std::vector<float>& points_of_discontinuity ){
    function = f;
    discontinuity_points = points_of_discontinuity;
}
float Function::get_y_at_x(float x, float x0, float y0){
    return function( x, x0, y0 );
};
std::vector<float> discontinuity_points;
