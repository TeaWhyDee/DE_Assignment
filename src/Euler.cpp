#include "Euler.h"

Euler::Euler( DerivativeFunction* func ){
    function = func;
}

GraphPoints Euler::get_points(float x0, float y0, float X, int N){
    function->update(x0, y0);
    const float len = X - x0;
    const float step = float(len) / float(N);

    GraphPoints points;
    float x = x0;
    float y = y0;
    points.graph_parts[points.size()-1].push_back( Point(x0, y0) );
    for (int i = 0; i < N; ++i){
        float x_prev = x;
        x += step;
        y += function->get_value(x_prev, y) * step;
        points.graph_parts[points.size()-1].push_back( Point(x, y) );
    }
    return points;
}
