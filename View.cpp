#include "View.h"

void View::update_x0(float val){
    x0 = val;
    update_chart();
}

void View::update_y0(float val){
    y0 = val;
    update_chart();
}

void View::update_X(float val){
    X = val;
    update_chart();
}

void View::update_N(float val){
    N = val;
    update_chart();
}

View::View(QChartView* chart, Function* func, DerivativeFunction* derivative_func){
    this->derivative_func = derivative_func;
    this->chartView = chart;
    this->func = func;
    this->exact_sol = new Exact( func );
    this->euler_sol = new Euler( derivative_func );
    this->ieuler_sol = new ImprovedEuler( derivative_func );
    this->rk_sol = new RungeKutta( derivative_func );
    update_chart();
}

void View::draw_graphs(){
    if ( show_exact ) {
        auto ExactPen = QPen();
        ExactPen.setWidth(3);
        ExactPen.setColor(QColor::fromRgb( 200, 100, 100 ));

        GraphPoints graph_points = exact_sol->get_points(x0, y0, X, N);
        for (int i = 0; i < graph_points.size(); ++i){
            QLineSeries* series = new QLineSeries();
            for (int j = 0; j < graph_points[i].size(); ++j){
                series->append(graph_points[i][j].x, graph_points[i][j].y);
            }
            series->setPen(ExactPen);
            series->setName("Exact");
            chartView->chart()->addSeries(series);
        }
    }

    if ( show_euler ) {
        auto EulerPen = QPen();
        EulerPen.setWidth(2);
        EulerPen.setColor(QColor::fromRgb( 100, 200, 100 ));

        GraphPoints graph_points_euler = euler_sol->get_points(x0, y0, X, N);
        for (int i = 0; i < graph_points_euler.size(); ++i){
            QLineSeries* series = new QLineSeries();
            for (int j = 0; j < graph_points_euler[i].size(); ++j){
                series->append(graph_points_euler[i][j].x, graph_points_euler[i][j].y);
            }
            series->setPen(EulerPen);
            series->setName("Euler");
            chartView->chart()->addSeries(series);
        }
    }

    if (show_ieuler) {
        auto iEulerPen = QPen();
        iEulerPen.setWidth(2);
        iEulerPen.setColor(QColor::fromRgb( 120, 220, 200 ));

        GraphPoints graph_points_ieuler = ieuler_sol->get_points(x0, y0, X, N);
        for (int i = 0; i < graph_points_ieuler.size(); ++i){
            QLineSeries* series = new QLineSeries();
            for (int j = 0; j < graph_points_ieuler[i].size(); ++j){
                series->append(graph_points_ieuler[i][j].x, graph_points_ieuler[i][j].y);
            }
            series->setPen(iEulerPen);
            series->setName("Improved Euler");
            chartView->chart()->addSeries(series);
        }
    }

    if ( show_rk ) {
        auto runge_kutta_pen = QPen();
        runge_kutta_pen.setWidth(2);
        runge_kutta_pen.setColor(QColor::fromRgb( 100, 100, 200 ));

        GraphPoints graph_points_rk = rk_sol->get_points(x0, y0, X, N);
        for (int i = 0; i < graph_points_rk.size(); ++i){
            QLineSeries* series = new QLineSeries();
            for (int j = 0; j < graph_points_rk[i].size(); ++j){
                series->append(graph_points_rk[i][j].x, graph_points_rk[i][j].y);
            }
            series->setPen(runge_kutta_pen);
            series->setName("Runge-Kutta");
            chartView->chart()->addSeries(series);
        }
    }
}

void View::draw_errors(){
    GraphPoints graph_points_exact = exact_sol->get_points(x0, y0, X, N);

    if ( show_euler ) {
        auto EulerPen = QPen();
        EulerPen.setWidth(2);
        EulerPen.setColor(QColor::fromRgb( 100, 200, 100 ));

        GraphPoints graph_points_euler = euler_sol->get_points(x0, y0, X, N);
        for (int i = 0; i < graph_points_euler.size(); ++i){
            QLineSeries* series = new QLineSeries();
            for (int j = 0; j < graph_points_euler[i].size(); ++j){
                float err = abs(graph_points_euler[i][j].y - graph_points_exact[i][j].y);
                series->append(graph_points_euler[i][j].x, err);
            }
            series->setPen(EulerPen);
            series->setName("Euler");
            chartView->chart()->addSeries(series);
        }
    }

    if (show_ieuler) {
        auto iEulerPen = QPen();
        iEulerPen.setWidth(2);
        iEulerPen.setColor(QColor::fromRgb( 120, 220, 200 ));

        GraphPoints graph_points_ieuler = ieuler_sol->get_points(x0, y0, X, N);
        for (int i = 0; i < graph_points_ieuler.size(); ++i){
            QLineSeries* series = new QLineSeries();
            for (int j = 0; j < graph_points_ieuler[i].size(); ++j){
                float err = abs(graph_points_ieuler[i][j].y - graph_points_exact[i][j].y);
                series->append(graph_points_ieuler[i][j].x, err);
            }
            series->setPen(iEulerPen);
            series->setName("Improved Euler");
            chartView->chart()->addSeries(series);
        }
    }

    if ( show_rk ) {
        auto runge_kutta_pen = QPen();
        runge_kutta_pen.setWidth(2);
        runge_kutta_pen.setColor(QColor::fromRgb( 100, 100, 200 ));

        GraphPoints graph_points_rk = rk_sol->get_points(x0, y0, X, N);
        for (int i = 0; i < graph_points_rk.size(); ++i){
            QLineSeries* series = new QLineSeries();
            for (int j = 0; j < graph_points_rk[i].size(); ++j){
                float err = abs(graph_points_rk[i][j].y - graph_points_exact[i][j].y);
                series->append(graph_points_rk[i][j].x, err);
            }
            series->setPen(runge_kutta_pen);
            series->setName("Runge-Kutta");
            chartView->chart()->addSeries(series);
        }
    }
}

void View::draw_errors_n(){
    auto EulerPen = QPen();
    EulerPen.setWidth(2);
    EulerPen.setColor(QColor::fromRgb( 200, 200, 100 ));
    QLineSeries* euler_series = new QLineSeries();
    euler_series->setPen(EulerPen);
    euler_series->setName("Euler");

    auto iEulerPen = QPen();
    iEulerPen.setWidth(2);
    iEulerPen.setColor(QColor::fromRgb( 100, 200, 200 ));
    QLineSeries* ieuler_series = new QLineSeries();
    ieuler_series->setPen(iEulerPen);
    ieuler_series->setName("Improved Euler");

    auto rk_pen = QPen();
    rk_pen.setWidth(2);
    rk_pen.setColor(QColor::fromRgb( 100, 100, 200 ));
    QLineSeries* rk_series = new QLineSeries();
    rk_series->setPen(rk_pen);
    rk_series->setName("Runge-Kutta");
    for (int n = 50; n < N; ++n){
        GraphPoints graph_points_exact = exact_sol->get_points(x0, y0, X, n);

        if ( show_euler ) {
            float av_err = 0;
            GraphPoints graph_points = euler_sol->get_points(x0, y0, X, n);
            for (int i = 0; i < graph_points.size(); ++i){
                for (int j = 0; j < graph_points[i].size(); ++j){
                    float err = abs(graph_points[i][j].y - graph_points_exact[i][j].y);
                    av_err += err;
                }
            }
            av_err /= n;
            euler_series->append(n, av_err);
        }

        if ( show_ieuler ) {
            float av_err = 0;
            GraphPoints graph_points = ieuler_sol->get_points(x0, y0, X, n);
            for (int i = 0; i < graph_points.size(); ++i){
                for (int j = 0; j < graph_points[i].size(); ++j){
                    float err = abs(graph_points[i][j].y - graph_points_exact[i][j].y);
                    av_err += err;
                }
            }
            av_err /= n;
            ieuler_series->append(n, av_err);
        }

        if ( show_rk ) {
            float av_err = 0;
            GraphPoints graph_points = rk_sol->get_points(x0, y0, X, n);
            for (int i = 0; i < graph_points.size(); ++i){
                for (int j = 0; j < graph_points[i].size(); ++j){
                    float err = abs(graph_points[i][j].y - graph_points_exact[i][j].y);
                    av_err += err;
                }
            }
            av_err /= n;
            rk_series->append(n, av_err);
        }
        
    }

    if ( show_euler ) {
        chartView->chart()->addSeries(euler_series);
    }
    if ( show_ieuler ) {
        chartView->chart()->addSeries(ieuler_series);
    }
    if ( show_rk ) {
        chartView->chart()->addSeries(rk_series);
    }
}

void View::update_chart(){
    chartView->chart()->removeAllSeries();

    if ( mode == Mode::GRAPHS ){
        draw_graphs();
    }
    else if ( mode == Mode::ERRORS ){
        draw_errors();
    }
    else if ( mode == Mode::ERRORS_N ){
        draw_errors_n();
    }

    chartView->chart()->createDefaultAxes();
}


float View::get_x0(){
    return x0;
}
float View::get_y0(){
    return y0;
}
float View::get_X(){
    return X;
}
int View::get_N(){
    return N;
}

void View::toggle_exact(int state){
    if ( state == 0 ){
        show_exact = false;
    }
    else {
        show_exact = true;
    }
    update_chart();
}

void View::toggle_euler(int state){
    if ( state == 0 ){
        show_euler = false;
    }
    else {
        show_euler = true;
    }
    update_chart();
}

void View::toggle_ieuler(int state){
    if ( state == 0 ){
        show_ieuler = false;
    }
    else {
        show_ieuler = true;
    }
    update_chart();
}

void View::toggle_rk(int state){
    if ( state == 0 ){
        show_rk = false;
    }
    else {
        show_rk = true;
    }
    update_chart();
}

void View::enable_graphs(bool _){
    mode = Mode::GRAPHS;
    update_chart();
}

void View::enable_errors(bool _){
    mode = Mode::ERRORS;
    update_chart();
}

void View::enable_errors_n(bool _){
    mode = Mode::ERRORS_N;
    update_chart();
}
