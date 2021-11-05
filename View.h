#pragma once

#include <QObject>
#include <QtCharts>
#include "Function.h"
#include "DerivativeFunction.h"
#include "Exact.h"
#include "Euler.h"
#include "ImpovedEuler.h"
#include "RungeKutta.h"
#include "GraphPoints.h"
#include "Constants.h"

enum Mode{
    GRAPHS, ERRORS, ERRORS_N
};

class View : public QObject{
    Q_OBJECT

    public:
        View(QChartView* chart, Function* exact_func, DerivativeFunction* derivative_func);
        void update_chart();

        float get_x0();
        float get_y0();
        float get_X();
        int get_N();

    public slots:
        void update_x0(float val);
        void update_y0(float val);
        void update_X(float val);
        void update_N(float val);

        void toggle_exact(int state);
        void toggle_euler(int state);
        void toggle_ieuler(int state);
        void toggle_rk(int state);

        void enable_graphs(bool _);
        void enable_errors(bool _);
        void enable_errors_n(bool _);

    private:
        void draw_graphs();
        void draw_errors();
        void draw_errors_n();

        QChartView* chartView;
        Function* func;
        DerivativeFunction* derivative_func;
        Exact* exact_sol;
        Euler* euler_sol;
        ImprovedEuler* ieuler_sol;
        RungeKutta* rk_sol;
        float x0 = 1;
        float y0 = 0;
        float X = 10;
        int N = 100;
        bool show_exact = true;
        bool show_euler = true;
        bool show_ieuler = true;
        bool show_rk = true;
        Mode mode = Mode::GRAPHS;
};
