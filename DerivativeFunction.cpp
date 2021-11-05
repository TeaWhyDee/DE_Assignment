#include "DerivativeFunction.h"

DerivativeFunction::DerivativeFunction(){}

void DerivativeFunction::update( float x0, float y0 ){
    this->x0 = x0;
    this->y0 = y0;
}

float DerivativeFunction::get_value(float x, float y){
    float val = 4/pow(x, 2) - y/x - pow(y,2);
    return val;
};
