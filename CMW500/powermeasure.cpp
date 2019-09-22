#include "powermeasure.h"
#include "ui_powermeasure.h"
#include <QStandardItem>
#include <QDebug>
#include <QFile>

#include <QDateTime>

void mySleep(int msec)
{
    QDateTime reachTime = QDateTime::currentDateTime().addMSecs(msec);
    while(QDateTime::currentDateTime() < reachTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 500);
    }
}



PowerMeasure::PowerMeasure(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PowerMeasure)
{
    ui->setupUi(this);
    iniTestItem();
    iniTableViewHeaders();
    iniAllTestItem();


}

PowerMeasure::~PowerMeasure()
{
    delete ui;
}

void PowerMeasure::iniTestItem()
{
//    vector<QString> frequencyPoint_TX;
    frequencyPoint_TX.push_back("850");
    frequencyPoint_TX.push_back("950");
    frequencyPoint_TX.push_back("1800");
    frequencyPoint_TX.push_back("1900");
    frequencyPoint_TX.push_back("100");
    frequencyPoint_TX.push_back("300");
    frequencyPoint_TX.push_back("500");
    frequencyPoint_TX.push_back("2300");
    frequencyPoint_TX.push_back("2700");
    frequencyPoint_TX.push_back("3300");
    frequencyPoint_TX.push_back("4000");
    frequencyPoint_TX.push_back("5000");
    frequencyPoint_TX.push_back("6000");
//    vector<QString> frequencyPoint_RX;
    frequencyPoint_RX.push_back("915");
    frequencyPoint_RX.push_back("1710");
    frequencyPoint_RX.push_back("1990");
    frequencyPoint_RX.push_back("2570");
    frequencyPoint_RX.push_back("5825");
//    vector<QString> powerPoint_COM_TX;
    powerPoint_COM_TX.push_back("-5");
    powerPoint_COM_TX.push_back("-10");
    powerPoint_COM_TX.push_back("-20");
    powerPoint_COM_TX.push_back("-30");
    powerPoint_COM_TX.push_back("-40");
    powerPoint_COM_TX.push_back("-50");
//    vector<QString> powerPoint_OUT_TX;
    powerPoint_OUT_TX.push_back("5");
    powerPoint_OUT_TX.push_back("0");
    powerPoint_OUT_TX.push_back("-10");
    powerPoint_OUT_TX.push_back("-20");
    powerPoint_OUT_TX.push_back("-30");
    powerPoint_OUT_TX.push_back("-40");
    powerPoint_OUT_TX.push_back("-50");
//    vector<QString> powerPoint_COM_RX;
    powerPoint_COM_RX.push_back("20");
    powerPoint_COM_RX.push_back("10");
    powerPoint_COM_RX.push_back("0");
    powerPoint_COM_RX.push_back("-10");
    powerPoint_COM_RX.push_back("-20");
    powerPoint_COM_RX.push_back("-30");
    powerPoint_COM_RX.push_back("-40");
    powerPoint_COM_RX.push_back("-50");

    ini_COM_TX();
    ini_OUT_TX();
    ini_COM_RX();
}

void PowerMeasure::ini_COM_TX()
{
    //ini COM_TX
    for(vector<QString>::iterator it_frequencyPoint_TX = frequencyPoint_TX.begin(); it_frequencyPoint_TX != frequencyPoint_TX.end(); ++it_frequencyPoint_TX){
        if( ((*it_frequencyPoint_TX) == "850") || ((*it_frequencyPoint_TX) == "950") || ((*it_frequencyPoint_TX) == "1800") || ((*it_frequencyPoint_TX) == "1900")){
            for(vector<QString>::iterator it_powerPoint_COM_TX = powerPoint_COM_TX.begin(); it_powerPoint_COM_TX != powerPoint_COM_TX.end(); ++it_powerPoint_COM_TX){
                RF1COM_TX[*it_frequencyPoint_TX].push_back(*it_powerPoint_COM_TX);
                RF2COM_TX[*it_frequencyPoint_TX].push_back(*it_powerPoint_COM_TX);
                RF3COM_TX[*it_frequencyPoint_TX].push_back(*it_powerPoint_COM_TX);
                RF4COM_TX[*it_frequencyPoint_TX].push_back(*it_powerPoint_COM_TX);
            }
        }else{
            RF1COM_TX[*it_frequencyPoint_TX].push_back(powerPoint_COM_TX_COMMON);
            RF2COM_TX[*it_frequencyPoint_TX].push_back(powerPoint_COM_TX_COMMON);
            RF3COM_TX[*it_frequencyPoint_TX].push_back(powerPoint_COM_TX_COMMON);
            RF4COM_TX[*it_frequencyPoint_TX].push_back(powerPoint_COM_TX_COMMON);
        }
    }
}

void PowerMeasure::ini_OUT_TX()
{
    //ini OUT_TX
    for(vector<QString>::iterator it_frequencyPoint_TX = frequencyPoint_TX.begin(); it_frequencyPoint_TX != frequencyPoint_TX.end(); ++it_frequencyPoint_TX){
        if( ((*it_frequencyPoint_TX) == "850") || ((*it_frequencyPoint_TX) == "950") || ((*it_frequencyPoint_TX) == "1800") || ((*it_frequencyPoint_TX) == "1900")){
            for(vector<QString>::iterator it_powerPoint_OUT_TX = powerPoint_OUT_TX.begin(); it_powerPoint_OUT_TX != powerPoint_OUT_TX.end(); ++it_powerPoint_OUT_TX){
                RF1OUT_TX[*it_frequencyPoint_TX].push_back(*it_powerPoint_OUT_TX);
                RF3OUT_TX[*it_frequencyPoint_TX].push_back(*it_powerPoint_OUT_TX);
            }
        }else{
            RF1OUT_TX[*it_frequencyPoint_TX].push_back(powerPoint_OUT_TX_COMMON);
            RF3OUT_TX[*it_frequencyPoint_TX].push_back(powerPoint_OUT_TX_COMMON);
        }
    }
}

void PowerMeasure::ini_COM_RX()
{
    //ini COM_RX
    for(vector<QString>::iterator it_frequencyPoint_RX = frequencyPoint_RX.begin(); it_frequencyPoint_RX != frequencyPoint_RX.end(); ++it_frequencyPoint_RX){
         for(vector<QString>::iterator it_powerPoint_COM_RX = powerPoint_COM_RX.begin(); it_powerPoint_COM_RX != powerPoint_COM_RX.end(); ++it_powerPoint_COM_RX){
             RF1COM_RX[*it_frequencyPoint_RX].push_back(*it_powerPoint_COM_RX);
             RF2COM_RX[*it_frequencyPoint_RX].push_back(*it_powerPoint_COM_RX);
             RF3COM_RX[*it_frequencyPoint_RX].push_back(*it_powerPoint_COM_RX);
             RF4COM_RX[*it_frequencyPoint_RX].push_back(*it_powerPoint_COM_RX);
         }
    }
}

void PowerMeasure::iniTableViewHeaders()
{
    model = new QStandardItemModel();
    model->setHorizontalHeaderLabels(strHeaders);
    this->ui->tb_powerMeasure->setModel(model);
    this->ui->tb_powerMeasure->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->ui->tb_powerMeasure->setStyleSheet("QHeaderView::section{ background:green; color:white; }");
    this->ui->tb_powerMeasure->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void PowerMeasure::iniTableViewData(vector<QString> & frequency, map<QString, vector<QString>> & test, QString testItem)
{
    //插入TX测试数据
    for(vector<QString>::iterator it_frequency = frequency.begin(); it_frequency != frequency.end(); ++it_frequency){
        for(vector<QString>::iterator it_power = test[*it_frequency].begin(); it_power != test[*it_frequency].end(); ++it_power, ++row){
            QStandardItem * Item_category = new QStandardItem(testItem);
            Item_category->setTextAlignment(Qt::AlignCenter);
            model->setItem(row, CATEGORY, Item_category);

            QStandardItem * Item_frequency = new QStandardItem(*it_frequency);
            Item_frequency->setTextAlignment(Qt::AlignCenter);
            model->setItem(row, FREQUENCY, Item_frequency);

            QStandardItem * Item_mark = new QStandardItem(*it_power);
            Item_mark->setTextAlignment(Qt::AlignCenter);
            model->setItem(row, MARK, Item_mark);

            if((100 <= (*it_frequency).toInt()) && ((*it_frequency).toInt() < 3300)){
                //0.3
                QStandardItem * Item_lower = new QStandardItem(QString::number((*it_power).toDouble() - 0.3));
                Item_lower->setTextAlignment(Qt::AlignCenter);
                model->setItem(row, LOWER, Item_lower);

                QStandardItem * Item_upper = new QStandardItem(QString::number((*it_power).toDouble() + 0.3));
                Item_upper->setTextAlignment(Qt::AlignCenter);
                model->setItem(row, UPPER, Item_upper);
            }else{
                QStandardItem * Item_lower = new QStandardItem(QString::number((*it_power).toDouble() - 0.8));
                Item_lower->setTextAlignment(Qt::AlignCenter);
                model->setItem(row, LOWER, Item_lower);

                QStandardItem * Item_upper = new QStandardItem(QString::number((*it_power).toDouble() + 0.8));
                Item_upper->setTextAlignment(Qt::AlignCenter);
                model->setItem(row, UPPER, Item_upper);
            }
        }
    }
    //插入RX测试数据
}

void PowerMeasure::iniAllTestItem()
{
    iniTableViewData(frequencyPoint_TX, RF1COM_TX, "RF1COM_TX_TEST");
    iniTableViewData(frequencyPoint_TX, RF1OUT_TX, "RF1OUT_TX_TEST");
    iniTableViewData(frequencyPoint_TX, RF2COM_TX, "RF2COM_TX_TEST");
    iniTableViewData(frequencyPoint_TX, RF3COM_TX, "RF3COM_TX_TEST");
    iniTableViewData(frequencyPoint_TX, RF3OUT_TX, "RF3OUT_TX_TEST");
    iniTableViewData(frequencyPoint_TX, RF4COM_TX, "RF4COM_TX_TEST");

    iniTableViewData(frequencyPoint_RX, RF1COM_RX, "RF1COM_RX_TEST");
    iniTableViewData(frequencyPoint_RX, RF2COM_RX, "RF2COM_RX_TEST");
    iniTableViewData(frequencyPoint_RX, RF3COM_RX, "RF3COM_RX_TEST");
    iniTableViewData(frequencyPoint_RX, RF4COM_RX, "RF4COM_RX_TEST");
}






