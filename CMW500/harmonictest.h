#ifndef HARMONICTEST_H
#define HARMONICTEST_H

#include <QWidget>

namespace Ui {
class HarmonicTest;
}

class HarmonicTest : public QWidget
{
    Q_OBJECT

public:
    explicit HarmonicTest(QWidget *parent = nullptr);
    ~HarmonicTest();

private:
    Ui::HarmonicTest *ui;
};

#endif // HARMONICTEST_H
