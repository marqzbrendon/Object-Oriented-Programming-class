#include "standardBird.h"

int StandardBird::hit()
{
   alive = false;
   return 1;
}

void StandardBird::draw()
{
   drawCircle(getPoint(), 15);
}
