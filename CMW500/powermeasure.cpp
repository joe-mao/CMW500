#include "powermeasure.h"
#include "ui_powermeasure.h"

PowerMeasure::PowerMeasure(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PowerMeasure)
{
    ui->setupUi(this);
}

PowerMeasure::~PowerMeasure()
{
    delete ui;
}


