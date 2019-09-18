#include "harmonictest.h"
#include "ui_harmonictest.h"

HarmonicTest::HarmonicTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HarmonicTest)
{
    ui->setupUi(this);


}

HarmonicTest::~HarmonicTest()
{
    delete ui;
}



