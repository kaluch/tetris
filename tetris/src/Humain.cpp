#include "../include/Humain.h"

void Humain::charger_touches(int tUp, int tDown,int tLeft,int tRight)
{
    setUp(tUp);
    setDown(tDown);
    setLeft(tLeft);
    setRight(tRight);
    setLastUp(false);
    setLastDown(true);
    setLastLeft(true);
    setLastRight(true);

}
