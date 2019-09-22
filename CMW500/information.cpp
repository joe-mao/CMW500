#include "information.h"
#include "ui_information.h"

#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>

bool writeInformationToFileWithCurrentTime(QString strInformation, QString flag)
{
    //flag == "[SCPI]"表示写入仪器的指令
    //flag == "[RESPONSE]"表示仪器反馈给机台的信息
    QDateTime timeStart = QDateTime::currentDateTime();//获取系统现在时间
    QString str = timeStart.toString("yyyy-MM-dd hh:mm:ss.zzz");//显示设置格式

    QFile file("500.log");
    if(!file.open(QIODevice::Append | QIODevice::Text)){
        return false;
    }
    QTextStream out(&file);

    out << str << " " << "[GPIB]" << " " << "[" + flag + "]" << " " << strInformation<<"\n";

    file.close();
    return true;
}


Information::Information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
}

Information::~Information()
{
    delete ui;
}

void Information::iniGPINInformation()
{
    CMW500::getInstance()->GPIB_ADDRESS = this->ui->le_CMW500Address->text();
    SignalAnalyzer::getInstance()->GPIB_ADDRESS = this->ui->le_SignalAnalyzerAddress->text();
    SignalGenerator::getInstance()->GPIB_ADDRESS = this->ui->le_SignalGeneratorAddress->text();
    PowerMeter::getInstance()->GPIB_ADDRESS = this->ui->le_PowerMeterAddress->text();
}

void Information::on_btn_start_clicked()
{
    //1. 连接GPIB，连接成功下一步，连接失败State显示失败返回
    iniGPINInformation();

    //2. 判断CheckBox选择了哪几项
    foreach(QObject * object, this->ui->groupBoxTestItem->children()){

        QCheckBox * checkBox_eg = qobject_cast<QCheckBox *>(object);
        if((checkBox_eg != nullptr) && (checkBox_eg->checkState() == Qt::Checked)){
            //获取选择项
            qDebug()<<checkBox_eg->text();
        }



    }

    //3. 测试选中的项，测试之前先获取SN
    //4. 生成的测试结果以SN保存
}
