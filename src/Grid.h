#pragma once

#include "GraphPoints.h"

class Grid {
    public:
        virtual GraphPoints get_points(float x0, float y0, float X, int N) = 0;
};
