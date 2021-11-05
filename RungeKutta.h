#pragma once

#include <vector>
#include <algorithm>
#include <stdio.h>
#include "Grid.h"
#include "DerivativeFunction.h"

class RungeKutta : Grid {
    public:
        GraphPoints get_points(float x0, float y0, float X, int N);
        RungeKutta( DerivativeFunction* func );
    private:
        DerivativeFunction* function;
};
