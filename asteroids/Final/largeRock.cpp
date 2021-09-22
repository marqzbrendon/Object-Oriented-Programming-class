#include "largeRock.h"

void LargeRock::draw()
{
   if (isAlive())
   {
      drawLargeAsteroid(getPoint(), 2);
   }
}
