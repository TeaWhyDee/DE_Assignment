#include "RungeKutta.h"

RungeKutta::RungeKutta( DerivativeFunction* func ){
    function = func;
}

GraphPoints RungeKutta::get_points(float x0, float y0, float X, int N){
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
        float k1 = step * function->get_value(x_prev, y);
        float k2 = step * function->get_value(x_prev + step/2, y + k1/2);
        float k3 = step * function->get_value(x_prev + step/2, y + k2/2);
        float k4 = step * function->get_value(x_prev + step, y + k3);
        y += 1.0/6.0 * (k1+2*k2+2*k3+k4);
        points.graph_parts[points.size()-1].push_back( Point(x, y) );
    }
    return points;
}
