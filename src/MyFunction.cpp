#include <stdio.h>
#include "MyFunction.h"

MyFunction::MyFunction(){}

void MyFunction::update( float x0, float y0 ){
    this->x0 = x0;
    this->y0 = y0;
    this->C = 1/pow(x0, 4) * (1/(x0*y0-2)+1.0/4.0);
    printf("\n==Function==\nx0:%f, y0:%f\nC: %f\n", x0, y0, this->C);
    discontinuity_points.clear();
    if ( C != 0 ) {
        discontinuity_points.push_back( - pow( 1.0/4.0/C, 0.25 ) );
    }
    discontinuity_points.push_back(0);
    if ( C != 0 ) {
        discontinuity_points.push_back( pow( 1.0/4.0/C, 0.25) );
    }
}

float MyFunction::get_y_at_x(float x){
    float y = 2/x + 1/(C*pow(x, 5)-x/4);
    return y;
};

std::vector<float> MyFunction::get_discontinuity_points(){
    return discontinuity_points;
}
