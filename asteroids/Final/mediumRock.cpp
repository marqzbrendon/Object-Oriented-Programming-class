#include "mediumRock.h"

void MediumRock::draw()
{
   if (isAlive())
   {
      drawMediumAsteroid(getPoint(), 5);
   }
}
