#pragma once

#include <vector>

struct Point{
    Point(float x, float y);
    float x;
    float y;
};

// Struct to store groups of points of a graph
// in the form vector<vector<Point>>.
// Groups are split by points of discontinuity and
// are in increasing order of smallest x coordinate.
struct Graph_points{
    // Disconnected parts of a graph.
    // A continuous graph would only have one part.
    std::vector<std::vector<Point>> gragh_parts;
};

class Grid {
    public:
        virtual Graph_points get_points(float x0, float y0, float X, int N) = 0;
};
