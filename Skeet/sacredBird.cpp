#include "sacredBird.h"

int SacredBird::hit()
{
   alive = false;
   return -10;
}

void SacredBird::draw()
{
   drawSacredBird(getPoint(), 15);
}
