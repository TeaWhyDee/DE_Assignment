#pragma once

#include <vector>
#include "Point.h"

// Struct to store groups of points of a graph
// in the form vector<vector<Point>>.
// Groups are split by points of discontinuity and
// are in increasing order of smallest x coordinate.
struct GraphPoints{
    GraphPoints(){
        graph_parts.push_back(std::vector<Point>());
    }
    // Disconnected parts of a graph.
    // A continuous graph would only have one part.
    std::vector<Point>& operator[](int idx);
    std::vector<std::vector<Point>> graph_parts;
    int size();
    void add_graph_part();
};
