#pragma once
#include "rocks.h"

class MediumRock : public Rock
{
private:

public:

   MediumRock()
   {
      speed.setDx(random(-1.3, 1.3));
      speed.setDy(random(-1.3, 1.3));
   }

   void draw();
};

