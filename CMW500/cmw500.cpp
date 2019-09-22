#include "cmw500.h"

CMW500 * CMW500::cmw500 = new CMW500;

CMW500 *CMW500::getInstance()
{
    return cmw500;
}

CMW500::CMW500(QObject *parent) : QObject(parent)
{

}

