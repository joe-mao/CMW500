#ifndef POWERMEASURE_H
#define POWERMEASURE_H

#include <QWidget>

namespace Ui {
class PowerMeasure;
}

class PowerMeasure : public QWidget
{
    Q_OBJECT


public:
    explicit PowerMeasure(QWidget *parent = nullptr);
     ~PowerMeasure();


private:
    Ui::PowerMeasure *ui;

};

#endif // POWERMEASURE_H
