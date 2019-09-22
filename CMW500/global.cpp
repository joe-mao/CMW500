#include "global.h"

Global * Global::globalInstance = new Global();

Global *Global::getInstance()
{
    return globalInstance;
}



Global::Global()
{

}
