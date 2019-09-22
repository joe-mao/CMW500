#include "global.h"
#include <QDateTime>
#include <QFile>
#include <QTextStream>

Global * Global::globalInstance = new Global();

Global *Global::getInstance()
{
    return globalInstance;
}



Global::Global()
{

}

bool Global::instrumentSet(ViSession device, QString command)
{
    ViStatus nRetStatus = viPrintf(device, (command + "\n").toStdString().c_str(), 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime(command + " Fail", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime(command, "SCPI");
    return true;
}


bool Global::writeInformationToFileWithCurrentTime(QString strInformation, QString flag)
{
    //flag == "[SCPI]"表示写入仪器的指令
    //flag == "[RESPONSE]"表示仪器反馈给机台的信息
    QDateTime timeStart = QDateTime::currentDateTime();//获取系统现在时间
    QString str = timeStart.toString("yyyy-MM-dd hh:mm:ss.zzz");//显示设置格式

    QFile file("TxRxPowerMeasure500.log");
    if(!file.open(QIODevice::Append | QIODevice::Text)){
        return false;
    }
    QTextStream out(&file);

    out << str << " " << "[GPIB]" << " " << "[" + flag + "]" << " " << strInformation<<"\n";

    file.close();
    return true;
}

