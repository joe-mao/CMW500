#include "signalgenerator.h"

SignalGenerator * SignalGenerator::signalGenerator = new SignalGenerator;

SignalGenerator *SignalGenerator::getInstance()
{
    return signalGenerator;
}

SignalGenerator::SignalGenerator(QObject * parent) : QObject (parent)
{

}
