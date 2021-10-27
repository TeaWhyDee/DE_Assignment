#pragma once

#include "Exact.h"
#include "MyExact.h"
#include <vector>
#include <math.h>

vector<Point> MyExact::get_points(float x0, float y0, float X, int N){
    float len = X - x0;
    float step = len / N;
    vector<Point> points;
    float x = x0;
    for (int i = 0; i < N; ++i){
        float y = get_y_at_x(x, x0, y0);
        points.push_back( Point(x, y) );
        x += step;
    }
    return points;
}

float MyExact::get_y_at_x(float x, float x0, float y0){
    float C = 1/pow(x0, 4) * (1/(x0*y0-2)+1);
    float y = 2/x + 1/(C*pow(x, 5)-x/4);
    return y;
}

vector<float> MyExact::discontinuity_points = { 1, 2 };
