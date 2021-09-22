#include "standardBird.h"

int StandardBird::hit()
{
   alive = false;
   boom.boom(getPoint());
   return 1;
}

void StandardBird::draw()
{
   drawCircle(getPoint(), 15);
}
