#ifndef INFORMATION_H
#define INFORMATION_H

#include <QWidget>
#include "cmw500.h"
#include "signalanalyzer.h"
#include "signalgenerator.h"
#include "powermeter.h"
#include <vector>
using namespace std;

namespace Ui {
class Information;
}

class Information : public QWidget
{
    Q_OBJECT
public:
    explicit Information(QWidget *parent = nullptr);
    ~Information();

signals:
    void powerMeasureSignal();

private:
    void iniGPINInformation();

private slots:
    void on_btn_start_clicked();

private:
    Ui::Information *ui;
    vector<QString> testItem;

};

#endif // INFORMATION_H
