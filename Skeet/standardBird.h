#pragma once
#include "bird.h"
class StandardBird : public Bird
{
private:

public:
   StandardBird()
   {
      position.setX(-200);
      position.setY(random(-200, 200));

      if (position.getY() < 0)
      {
         speed.setDx(random(1, 4));
         speed.setDy(random(1, 4));
      }

      else
      {
         speed.setDx(random(1, 4));
         speed.setDy(random(-4, -1));
      }
   }

   int hit();
   void draw();

};

