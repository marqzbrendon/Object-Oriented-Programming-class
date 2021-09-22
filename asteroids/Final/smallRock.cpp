#include "smallRock.h"

void SmallRock::draw()
{
   if (isAlive())
   {
      drawSmallAsteroid(getPoint(), 10);
   }
}

