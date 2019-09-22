#include "cmw500.h"
#include <cstring>
using namespace std;



CMW500 * CMW500::cmw500 = new CMW500;

CMW500 *CMW500::getInstance()
{
    return cmw500;
}

CMW500::CMW500(QObject *parent) : QObject(parent)
{

}

bool CMW500::getSN()
{
    if(!Global::getInstance()->instrumentSet(SESSION, "*IDN?")){ /*this->ui->lb_testState->setText("ERROR"); return false;*/ }
    ViByte rdBuff[255] = {};
    QString qstr = "";
    ViStatus nRetStatus;
    nRetStatus = viScanf(SESSION, "%s", rdBuff);
    if(nRetStatus != VI_SUCCESS){
        Global::getInstance()->writeInformationToFileWithCurrentTime("READ CMW Fail", "SCPI");
        return false;
    }

    Global::getInstance()->writeInformationToFileWithCurrentTime("READ CMW SUCCESS", "SCPI");
    string str = (char *)rdBuff;
    qstr = QString::fromStdString(str);

    serialNumber = qstr.split('/').at(1).split(',').at(0);
    return true;
}


