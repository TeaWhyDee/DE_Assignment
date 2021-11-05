#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QtCharts>
#include <QSlider>
#include "View.h"
#include "Exact.h"
#include "MyFunction.h"
#include "TextSlider.h"
#include "Function.h"
#include "DerivativeFunction.h"

class Controller : public QWidget {
    Q_OBJECT

    public:
        Controller(QWidget *parent = nullptr);
};
