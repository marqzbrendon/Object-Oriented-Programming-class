#pragma once
#include "bird.h"
class MegaBird : public Bird
{
private:
   int hits;
   int count;

public:

   MegaBird()
   {
      position.setX(-200);
      position.setY(random(-200, 200));

      if (position.getY() < 0)
      {
         speed.setDx(random(0.5, 1.2));
         speed.setDy(random(0.5, 1.2));
      }

      else
      {
         speed.setDx(random(0.5, 1.2));
         speed.setDy(random(-1.2, -0.5));
      }

      hits = 0;
      count = 9;
   }

   int hit();
   void draw();

};

