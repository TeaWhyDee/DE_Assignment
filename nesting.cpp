#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QtCharts>
#include "nesting.h"

Layouts::Layouts(QWidget *parent) : QWidget(parent) {

    //                                LAYOUTS
    auto *vbox = new QVBoxLayout();
    auto *hbox = new QHBoxLayout(this);

    /* connect(add, &QPushButton::clicked, *this, &Layouts::changeName("str")); */

    //                                CHART
    QChart* chart= new QChart();
    QLineSeries* series = new QLineSeries();
    series->append(2, 4);
    series->append(5, 10);
    QChartView* chartView = new QChartView(chart);
    chartView->chart()->addSeries(series);
    chartView->chart()->createDefaultAxes();

    //                                SLIDERS
    auto *label = new QLabel();
    label->setText("X ");
    auto font = label->font();
    font.setWeight(800);
    font.setPixelSize(20);
    label->setFont(font);

    auto *slider_box = new QHBoxLayout();
    auto *slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(10);

    auto *text_slider_val = new QLineEdit();
    /* text_slider_val->setInputMask("d01;_"); */
    auto *font_metrics = new QFontMetrics((text_slider_val)->font());
    text_slider_val->setFixedHeight(10 + (font_metrics->lineSpacing()));
    text_slider_val->setFixedWidth(5 * (font_metrics->averageCharWidth()));
    /* connect(text_slider_val, &QLineEdit, text_slider_val, SLOT(selectAll())); */

    /* text_min->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); */
    /* text_min. */
    /* connect(text_min, &QTextEdit::textChanged, text_min, [=](){ */
    /*         /1* int diff = text_min->toPlainText().length() - 3; *1/ */
    /*         /1* const QString newStr = text_min->toPlainText().chopped(diff); *1/ */
    /*         /1* newStr.chop(diff); *1/ */
    /*         text_min->setText(newStr); */
    /*         QTextCursor cursor(text_min->textCursor()); */
    /*         cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor); */
    /*         text_min->setTextCursor(cursor); */

    /*         QRegExp re("\\d*"); */
    /*         if (!re.exactMatch(text_min->toPlainText())) { */
    /*         text_min->setTextBackgroundColor(QColor(255, 0, 0)); */
    /*         } */
    /*         }); */

    slider_box->addWidget(label);
    slider_box->setSpacing(3);
    slider_box->addWidget(text_slider_val);
    slider_box->addWidget(slider);


    //                              COMBINING RIGHT SIDE (SETTINGS ETC.)
    vbox->setSpacing(3);
    vbox->addLayout(slider_box);
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
