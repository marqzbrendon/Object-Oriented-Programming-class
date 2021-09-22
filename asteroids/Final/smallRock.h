#pragma once
#include "rocks.h"

class SmallRock : public Rock
{
private:

public:

   SmallRock()
   {
      speed.setDx(random(-1.5, 1.5));
      speed.setDy(random(-1.5, 1.5));
   }

   void draw();
};

