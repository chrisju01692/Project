#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <QObject>

class TestSuite : public QObject
{
    Q_OBJECT

private slots:
    void testWidgetsExist();
    void testSliderUpdatesSpinBox();
    void testSpinBoxUpdatesSlider();
};

#endif // TESTSUITE_H
