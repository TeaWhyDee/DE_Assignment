#pragma once

#include <vector>
#include "Exact.h"

Graph_points Exact::get_points(float x0, float y0, float X, int N){
    float len = X - x0;
    float step = len / N;
    Graph_points points;
    points.gragh_parts.push_back(std::vector<Point>());
    float x = x0;
    int graph_part = 0;
    for (int i = 0; i < N; ++i){
        float y = function.get_y_at_x(x, x0, y0);
        points.gragh_parts[graph_part].push_back( Point(x, y) );
        x += step;
    }
    return points;
};

Exact::Exact( Function& func ){
    function = func;
}
