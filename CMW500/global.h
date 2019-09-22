#ifndef GLOBAL_H
#define GLOBAL_H
#include <QString>
#include "visa.h"


class Global
{ 
public:
    static Global * getInstance();
    bool writeInformationToFileWithCurrentTime(QString strInformation, QString flag);
    bool instrumentSet(ViSession device, QString command);
private:
    Global();
    Global(const Global * ) = delete;
    static Global * globalInstance;

};

#endif // GLOBAL_H
