#pragma once
#include "rocks.h"

class SmallRock : public Rock
{
private:

public:

   SmallRock()
   {
      speed.setDx(random(-0.9, 0.9));
      speed.setDy(random(-0.9, 0.9));
   }

   void draw();
};

