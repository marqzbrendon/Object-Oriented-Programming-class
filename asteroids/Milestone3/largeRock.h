#pragma once
#include "rocks.h"

class LargeRock : public Rock
{
private:


public:

   LargeRock()
   {
      speed.setDx(random(-1.0, 1.0));
      speed.setDy(random(-1.0, 1.0));
   }

   void draw();
};

