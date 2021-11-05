#include <QApplication>
#include <stdio.h>
#include <math.h>
#include "Controller.h"
#include "MyFunction.h"
#include "Exact.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Controller window(nullptr);

    window.setWindowTitle("Controller");
    window.show();

    return app.exec();
}
