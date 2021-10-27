#include <QApplication>
#include <stdio.h>
#include <math.h>
#include "nesting.h"
#include "Exact.h"

int main(int argc, char *argv[]) {

    auto my_func = [](float x, float x0, float y0) {
        float C = 1/pow(x0, 4) * (1/(x0*y0-2)+1);
        float y = 2/x + 1/(C*pow(x, 5)-x/4);
        return y;
    };

    std::vector<float> pts_of_discont = { 0 };
    Function func = Function(my_func, pts_of_discont);
    auto exact_sol = Exact( func );

    Graph_points points = exact_sol.get_points(0, 1, 7, 100);

    for (int i = 0; i < points.size(); ++i){
        printf("%f:%f", points[i].x, points[i].y);
        if ( i < points.size() - 1 ){
            printf(", ");
        }
    }

    QApplication app(argc, argv);

    Layouts window;

    window.setWindowTitle("Layouts");
    window.show();

    return app.exec();
}
