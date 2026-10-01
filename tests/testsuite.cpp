#include "testsuite.h"
#include "mainwindow.h"

#include <QtTest>
#include <QSlider>
#include <QSpinBox>

void TestSuite::testWidgetsExist()
{
    MainWindow window;

    QSlider *slider = window.findChild<QSlider *>("slider");
    QSpinBox *spinBox = window.findChild<QSpinBox *>("spinBox");

    QVERIFY2(slider != nullptr, "QSlider does not exist");
    QVERIFY2(spinBox != nullptr, "QSpinBox does not exist");
    QCOMPARE(slider->minimum(), 0);
    QCOMPARE(slider->maximum(), 100);
    QCOMPARE(spinBox->minimum(), 0);
    QCOMPARE(spinBox->maximum(), 100);
}

void TestSuite::testSliderUpdatesSpinBox()
{
    MainWindow window;

    QSlider *slider = window.findChild<QSlider *>("slider");
    QSpinBox *spinBox = window.findChild<QSpinBox *>("spinBox");

    QVERIFY(slider != nullptr);
    QVERIFY(spinBox != nullptr);

    slider->setValue(42);
    QCOMPARE(spinBox->value(), 42);
}

void TestSuite::testSpinBoxUpdatesSlider()
{
    MainWindow window;

    QSlider *slider = window.findChild<QSlider *>("slider");
    QSpinBox *spinBox = window.findChild<QSpinBox *>("spinBox");

    QVERIFY(slider != nullptr);
    QVERIFY(spinBox != nullptr);

    spinBox->setValue(73);
    QCOMPARE(slider->value(), 73);
}
