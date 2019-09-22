#ifndef POWERMETER_H
#define POWERMETER_H

#include <QObject>

class PowerMeter : public QObject
{
    Q_OBJECT
public:
    static PowerMeter * getInstance();
private:
    PowerMeter(QObject * parent = nullptr);
    PowerMeter(PowerMeter &) = delete;
    static PowerMeter * powerMeter;
public:
    QString serialNumber = "";
    QString config = "";
    QString powerSensorConfig = "";
    bool errorFlag = true;//true表示有错误发生，false表示没有错误发生，连接GPIB的时候获取
    QString Result;
    QString GPIB_ADDRESS;
    QString LAN_ADDRESS;
};

#endif // POWERMETER_H
