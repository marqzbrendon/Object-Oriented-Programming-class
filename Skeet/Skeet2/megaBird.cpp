#include "megaBird.h"

int MegaBird::hit()
{
   if (hits < 8)
   {
      ++hits;
      --count;
      return 1;
   }

   else
   {
      alive = false;
      boom.boom(getPoint());
      return 6;
   }
}

void MegaBird::draw()
{
   drawLargeAsteroid(getPoint(), 20, count);
}
