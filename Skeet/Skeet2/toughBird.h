#pragma once
#include "bird.h"
class ToughBird : public Bird
{
private:

   int hits;
   int count;

public:


   ToughBird()
   {
      position.setX(-200);
      position.setY(random(-200, 200));

      if (position.getY() < 0)
      {
         speed.setDx(random(1, 2));
         speed.setDy(random(1, 2));
      }

      else
      {
         speed.setDx(random(1, 2));
         speed.setDy(random(-2, -1));
      }

      hits = 0;
      count = 3;
   }

   int hit();
   void draw();
};

