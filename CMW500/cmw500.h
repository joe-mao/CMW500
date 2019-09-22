#ifndef CMW500_H
#define CMW500_H

#include "visa.h"
#include <QObject>

class CMW500 : public QObject
{
    Q_OBJECT
public:
    static CMW500 * getInstance();
private:
    explicit CMW500(QObject *parent = nullptr);
    CMW500(const CMW500 &) = delete ;
    static CMW500 * cmw500;
signals:

public slots:

public:
    QString serialNumber = "";
    QString config = "";
    bool errorFlag = true;//true表示有错误发生，false表示没有错误发生，连接GPIB的时候获取
    bool selfChecking = true;//true表示仪器处于自检状态，false表示不处于自检状态，连接GPIB的时候获取
    QString GPIB_ADDRESS;
    QString LAN_ADDRESS;
};

#endif // CMW500_H
