#ifndef PHASENOISE_H
#define PHASENOISE_H

#include <QWidget>

namespace Ui {
class PhaseNoise;
}

class PhaseNoise : public QWidget
{
    Q_OBJECT

public:
    explicit PhaseNoise(QWidget *parent = nullptr);
    ~PhaseNoise();


private:
    Ui::PhaseNoise *ui;

};

#endif // PHASENOISE_H
