#pragma once
#include "rocks.h"

class MediumRock : public Rock
{
private:

public:

   MediumRock()
   {
      speed.setDx(random(-0.7, 0.7));
      speed.setDy(random(-0.7, 0.7));
   }

   void draw();
};

