#ifndef POWERMEASURE_H
#define POWERMEASURE_H

#include <QWidget>
#include <QStandardItemModel>
#include <vector>
#include <map>

#include "visa.h"


using namespace std;

namespace Ui {
class PowerMeasure;
}

class PowerMeasure : public QWidget
{
    Q_OBJECT

    enum column{
        CATEGORY,
        FREQUENCY,
        LOWER,
        VALUE,
        UPPER,
        MARK,
        RESULT
    };


public:
    explicit PowerMeasure(QWidget *parent = nullptr);
     ~PowerMeasure();
    void iniTestItem();
    void ini_COM_TX();
    void ini_OUT_TX();
    void ini_COM_RX();

    void iniTableViewHeaders();
    void iniTableViewData(vector<QString> & frequency,  map<QString, vector<QString>> & test, QString testItem);
    void iniAllTestItem();

private slots:
    void onPowerMeasureSignal();

private:
    Ui::PowerMeasure *ui;
    QStandardItemModel * model;
    int row = 0;
    QStringList strHeaders = {"Category(TX/RX)" ,"Frequency(MHz)", "Lower(dBm)", "Value", "Upper(dBm)", "Mark", "Result"};


    //iniData
    vector<QString> frequencyPoint_TX;
    vector<QString> frequencyPoint_RX;
    vector<QString> powerPoint_COM_TX;
    vector<QString> powerPoint_OUT_TX;
    vector<QString> powerPoint_COM_RX;

    QString powerPoint_COM_TX_COMMON = "-10";
    QString powerPoint_OUT_TX_COMMON = "0";

    double limit_100MHz_3300MHz_TX = 0.3;
    double limit_3300MHz_6000MHz_TX = 0.8;
    double limit_All_RX = 0.7;



    //testItem
    map<QString, vector<QString>> RF1COM_TX;
    map<QString, vector<QString>> RF1OUT_TX;
    map<QString, vector<QString>> RF2COM_TX;
    map<QString, vector<QString>> RF3COM_TX;
    map<QString, vector<QString>> RF3OUT_TX;
    map<QString, vector<QString>> RF4COM_TX;

    map<QString, vector<QString>> RF1COM_RX;
    map<QString, vector<QString>> RF2COM_RX;
    map<QString, vector<QString>> RF3COM_RX;
    map<QString, vector<QString>> RF4COM_RX;
     //testResult
    map<QString, map<QString, QString>> RF1COM_TX_Result;
    map<QString, map<QString, QString>> RF1OUT_TX_Result;
    map<QString, map<QString, QString>> RF2COM_TX_Result;
    map<QString, map<QString, QString>> RF3COM_TX_Result;
    map<QString, map<QString, QString>> RF3OUT_TX_Result;
    map<QString, map<QString, QString>> RF4COM_TX_Result;

    map<QString, map<QString, QString>> RF1COM_RX_Result;
    map<QString, map<QString, QString>> RF2COM_RX_Result;
    map<QString, map<QString, QString>> RF3COM_RX_Result;
    map<QString, map<QString, QString>> RF4COM_RX_Result;
};

#endif // POWERMEASURE_H
