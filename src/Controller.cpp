#include "Controller.h"

Controller::Controller(QWidget *parent) : QWidget(parent){
    //                                    
    auto *vbox = new QVBoxLayout();
    auto *hbox = new QHBoxLayout(this);
    QChart* chart= new QChart();
    QChartView* chartView = new QChartView(chart);

    auto exact_func = new MyFunction();
    auto derivative_func = new DerivativeFunction();

    View* view = new View(chartView, exact_func, derivative_func);

    //                          MODE (GRAPHS, ERRORS, ERRORS on N)
    QRadioButton * button_graphs = new QRadioButton("Graphs");
    QRadioButton * button_errors = new QRadioButton("Error on x");
    QRadioButton * button_errors_N = new QRadioButton("Av. Error on N");
    button_graphs->setChecked(true);
    QButtonGroup * group = new QButtonGroup;
    group->addButton(button_graphs);
    group->addButton(button_errors);
    group->addButton(button_errors_N);
    group->setExclusive(true);

    vbox->addWidget(button_graphs);
    vbox->addWidget(button_errors);
    vbox->addWidget(button_errors_N);
    vbox->addSpacing(10);

    connect(button_graphs, &QRadioButton::clicked, view, &View::enable_graphs);
    connect(button_errors, &QRadioButton::clicked, view, &View::enable_errors);
    connect(button_errors_N, &QRadioButton::clicked, view, &View::enable_errors_n);

    // CHART
    //                                SLIDERS
    TextSlider *x0_slider = new TextSlider("x0 ", view->get_x0());
    connect(x0_slider, &TextSlider::new_value, view, &View::update_x0);
    vbox->addLayout(x0_slider);

    TextSlider *y0_slider = new TextSlider("y0 ", view->get_y0());
    connect(y0_slider, &TextSlider::new_value, view, &View::update_y0);
    vbox->addLayout(y0_slider);

    TextSlider *X_slider = new TextSlider("X  ", view->get_X());
    connect(X_slider, &TextSlider::new_value, view, &View::update_X);
    vbox->addLayout(X_slider);

    TextSlider *N_slider = new TextSlider("N  ", view->get_N());
    connect(N_slider, &TextSlider::new_value, view, &View::update_N);
    vbox->addLayout(N_slider);

    auto *exact_button = new QCheckBox("Exact");
    exact_button->setChecked(true);
    connect(exact_button, &QCheckBox::stateChanged, view, &View::toggle_exact);
    connect(button_graphs, &QRadioButton::clicked, exact_button, &QCheckBox::setEnabled);
    connect(button_errors, &QRadioButton::clicked, exact_button, &QCheckBox::setDisabled);
    connect(button_errors_N, &QRadioButton::clicked, exact_button, &QCheckBox::setDisabled);

    auto *euler_button = new QCheckBox("Euler");
    euler_button->setChecked(true);
    connect(euler_button, &QCheckBox::stateChanged, view, &View::toggle_euler);

    auto *ieuler_button = new QCheckBox("Improved Euler");
    ieuler_button->setChecked(true);
    connect(ieuler_button, &QCheckBox::stateChanged, view, &View::toggle_ieuler);

    auto *rk_button = new QCheckBox("Runge-Kutta");
    rk_button->setChecked(true);
    connect(rk_button, &QCheckBox::stateChanged, view, &View::toggle_rk);


    //                              COMBINING RIGHT SIDE (SETTINGS ETC.)
    vbox->setSpacing(3);
    vbox->addSpacing(10);
    vbox->addWidget(exact_button);
    vbox->addWidget(euler_button);
    vbox->addWidget(ieuler_button);
    vbox->addWidget(rk_button);
    vbox->addStretch(1);

    // Hack to specify maximum width of a layout
    QWidget *controlsRestrictorWidget = new QWidget();
    controlsRestrictorWidget->setLayout(vbox);
    controlsRestrictorWidget->setMaximumWidth(300);

    //                              COMBINING EVERYTHING
    hbox->addWidget(chartView);
    hbox->addSpacing(15);
    hbox->QLayout::addWidget(controlsRestrictorWidget);


    setLayout(hbox);
}
