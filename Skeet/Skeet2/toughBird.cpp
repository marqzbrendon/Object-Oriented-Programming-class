#include "toughBird.h"

int ToughBird::hit()
{
   if (hits < 2)
   {
      ++hits;
      --count;
      return 1;
   }

   else
   {
      alive = false;
      boom.boom(getPoint());
      return 3;
   }
}

void ToughBird::draw()
{
   drawToughBird(getPoint(), 15, count);
}
