#include "phasenoise.h"
#include "ui_phasenoise.h"

PhaseNoise::PhaseNoise(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PhaseNoise)
{
    ui->setupUi(this);

}

PhaseNoise::~PhaseNoise()
{
    delete ui;
}
