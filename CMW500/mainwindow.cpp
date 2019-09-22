#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->tabWidget->setVisible(false);
    this->ui->tabWidget->clear();//清除所有页面
    //this->ui->tabWidget->tabsClosable();//Page有关闭按钮，可被关闭
    this->setCentralWidget(this->ui->tabWidget);
    this->setWindowState(Qt::WindowMaximized);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //绘制窗口背景
    Q_UNUSED(event);

    QPainter painter(this);
    //painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/image/image/sea.jpeg"));
    painter.drawPixmap(0, this->ui->mainToolBar->height(), this->width(), this->height() - this->ui->mainToolBar->height() - this->ui->statusBar->height(), QPixmap(":/image/image/sea.jpeg"));
}

void MainWindow::on_actionTest_triggered()
{
        information = new Information(this);
        information->setAttribute(Qt::WA_DeleteOnClose);//关闭时自动删除


        powerMeasure = new PowerMeasure(this);
        powerMeasure->setAttribute(Qt::WA_DeleteOnClose);//关闭时自动删除

        harmonicTest = new HarmonicTest(this);
        harmonicTest->setAttribute(Qt::WA_DeleteOnClose);//关闭时自动删除

        phaseNoise = new PhaseNoise(this);
        phaseNoise->setAttribute(Qt::WA_DeleteOnClose);//关闭时自动删除


        this->ui->tabWidget->addTab(information, "Information");

        this->ui->tabWidget->addTab(powerMeasure, "PowerMeasure");

        this->ui->tabWidget->addTab(harmonicTest, "HarmonicTest");

        this->ui->tabWidget->addTab(phaseNoise, "PhaseNoise");

        connect(information, SIGNAL(powerMeasureSignal()), powerMeasure, SLOT(onPowerMeasureSignal()));

        this->ui->tabWidget->setVisible(true);

}
