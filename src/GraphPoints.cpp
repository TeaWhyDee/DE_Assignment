#pragma once

#include "GraphPoints.h"
#include <stdio.h>

int GraphPoints::size(){
    return graph_parts.size();
}

std::vector<Point>& GraphPoints::operator[](int idx){
    return graph_parts[idx];
}

void GraphPoints::add_graph_part(){
    graph_parts.push_back(std::vector<Point>());
    printf("new graph part");
}
