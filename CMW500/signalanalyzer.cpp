#include "signalanalyzer.h"

SignalAnalyzer * SignalAnalyzer::signalAnalyzer = new SignalAnalyzer;

SignalAnalyzer *SignalAnalyzer::getInstance()
{
    return signalAnalyzer;
}

SignalAnalyzer::SignalAnalyzer(QObject *parent) : QObject(parent)
{

}
