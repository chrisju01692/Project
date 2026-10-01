#include "mainwindow.h"

#include <QSlider>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      slider(nullptr),
      spinBox(nullptr)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    slider = new QSlider(Qt::Horizontal, centralWidget);
    spinBox = new QSpinBox(centralWidget);

    slider->setObjectName("slider");
    spinBox->setObjectName("spinBox");

    slider->setRange(0, 100);
    spinBox->setRange(0, 100);

    layout->addWidget(slider);
    layout->addWidget(spinBox);

    setCentralWidget(centralWidget);
    setWindowTitle("Slider and Spin Box");
    resize(400, 140);

    connect(slider, &QSlider::valueChanged,
            spinBox, &QSpinBox::setValue);

    connect(spinBox, &QSpinBox::valueChanged,
            slider, &QSlider::setValue);
}
