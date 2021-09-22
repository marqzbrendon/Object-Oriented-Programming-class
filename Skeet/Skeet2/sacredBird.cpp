#include "sacredBird.h"

int SacredBird::hit()
{
   alive = false;
   boom.boom(getPoint());
   return -10;
}

void SacredBird::draw()
{
   drawSacredBird(getPoint(), 15);
}
