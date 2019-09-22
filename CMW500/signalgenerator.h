#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <QObject>

class SignalGenerator : public QObject
{
    Q_OBJECT
public:
    static SignalGenerator * getInstance();
private:
    SignalGenerator(QObject * parent = nullptr);
    SignalGenerator(const SignalGenerator & ) = delete;
    static SignalGenerator * signalGenerator;
public:
    QString serialNumber = "";
    QString config = "";
    bool errorFlag = true;//true表示有错误发生，false表示没有错误发生，连接GPIB的时候获取
    QString frequency;
    QString power;
    QString GPIB_ADDRESS;
    QString LAN_ADDRESS;

};

#endif // SIGNALGENERATOR_H
