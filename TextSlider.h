#pragma once

#include <QVBoxLayout>
#include <QListWidget>
#include <QSlider>
#include <QLabel>
#include <QLineEdit>
#include <iostream>
#include "Constants.h"

class TextSlider : public QHBoxLayout {
    Q_OBJECT

public:
        TextSlider(QString variable);
        TextSlider(QString variable, float init_val);
        TextSlider(QString variable, int init_val);

signals:
        void new_value(float val);

public slots:
            void updateval_float(float val);
            void updateval_string(QString val);

private:
        QLabel *label = new QLabel();
        QHBoxLayout *slider_box = new QHBoxLayout();
        QSlider *slider = new QSlider(Qt::Horizontal);
        QLineEdit *text_slider_val = new QLineEdit();
        int multiplier = 1;
};
