#include "powermeter.h"

PowerMeter * PowerMeter::powerMeter = new PowerMeter();

PowerMeter *PowerMeter::getInstance()
{
    return powerMeter;
}

PowerMeter::PowerMeter(QObject * parent) : QObject (parent)
{

}
