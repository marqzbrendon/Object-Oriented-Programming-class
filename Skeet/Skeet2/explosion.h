#include "point.h"
#include "uiDraw.h"

#pragma once
class Explosion
{
private:
   
   bool bottom;
   bool top;
   bool left;
   bool right;

   Point pB;
   Point pT;
   Point pL;
   Point pR;


public:

   Explosion()
   {
      bottom = false;
      top = false;
      left = false;
      right = false;
   }

   void boomB(Point pB);
   void boomT(Point pT);
   void boomL(Point pL);
   void boomR(Point pR);
   void boom(Point p);

};

