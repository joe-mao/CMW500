#ifndef SIGNALANALYZER_H
#define SIGNALANALYZER_H

#include <QObject>

class SignalAnalyzer : public QObject
{
    Q_OBJECT
public:
    static SignalAnalyzer * getInstance();
private:
    explicit SignalAnalyzer(QObject *parent = nullptr);
    SignalAnalyzer(const SignalAnalyzer &) = delete;
    static SignalAnalyzer * signalAnalyzer;
signals:

public slots:

public:
    QString serialNumber = "";
    QString config = "";
    bool errorFlag = true;//true表示有错误发生，false表示没有错误发生，连接GPIB的时候获取
    QString frequency;
    QString span;
    QString GPIB_ADDRESS;
    QString LAN_ADDRESS;
};

#endif // SIGNALANALYZER_H
