#include "TextSlider.h"

TextSlider::TextSlider(QString variable, float init_val) :
    TextSlider::TextSlider(variable) {
        /* std::cout << variable.toStdString() << ": " << init_val << std::endl; */

        multiplier = SLIDERSCALE;
        QString text = QString::number(init_val);
        text_slider_val->setText(text);
        slider->setMinimum(1);
        slider->setMaximum(1000);
        slider->setValue((int)(init_val*multiplier));
    }

TextSlider::TextSlider(QString variable, int init_val) :
    TextSlider::TextSlider(variable) {

        QString text = QString::number(init_val);
        text_slider_val->setText(text);
        slider->setMinimum(10);
        slider->setMaximum(1000);
        slider->setValue((int)init_val);
    }

TextSlider::TextSlider(QString variable){
    /* auto *label = new QLabel(); */
    label->setText(variable);
    auto font = label->font();
    font.setWeight(800);
    font.setPixelSize(20);
    label->setFont(font);

    auto *font_metrics = new QFontMetrics((text_slider_val)->font());
    text_slider_val->setFixedHeight(10 + (font_metrics->lineSpacing()));
    text_slider_val->setFixedWidth(5 * (font_metrics->averageCharWidth()));

    this->addWidget(label);
    this->setSpacing(3);
    this->addWidget(text_slider_val);
    this->addWidget(slider);

    QWidget::connect(slider, &QSlider::sliderMoved, this, &TextSlider::updateval_float);
    QWidget::connect(text_slider_val, &QLineEdit::textEdited, this, &TextSlider::updateval_string);
}

void TextSlider::updateval_float(float val){
    QString text = QString::number(val/multiplier);
    text_slider_val->setText(text);
    emit new_value(val / multiplier);
}

void TextSlider::updateval_string(QString string){
    bool ok = false;
    float val = string.toFloat(&ok) * multiplier;
    if (!ok){
        return;
    }
    int val_int = (int)val;
    slider->setValue(val_int);
    emit new_value(val / multiplier);
}

/* void TextSlider::updateval(QString val){ */
