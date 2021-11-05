#pragma once

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <vector>
#include "Grid.h"
#include "Function.h"

class Exact : Grid {
    public:
        GraphPoints get_points(float x0, float y0, float X, int N);
        Exact( Function* func );
    private:
        Function* function;
};
