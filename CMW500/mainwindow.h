#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "powermeasure.h"
#include "harmonictest.h"
#include "phasenoise.h"
#include "information.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent * event);

private slots:
    void on_actionTest_triggered();

private:
    Ui::MainWindow *ui;

    PowerMeasure * powerMeasure;
    HarmonicTest * harmonicTest;
    PhaseNoise * phaseNoise;
    Information * information;
};

#endif // MAINWINDOW_H
