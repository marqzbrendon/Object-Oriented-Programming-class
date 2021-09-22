#include "explosion.h"

void Explosion::boomB(Point pB)
{
   pB.setY(pB.getY() - 0.5);
   bool fTop = false;
   bool fLeft = false;
   bool fRight = false;
   drawLanderFlames(pB, bottom, fTop, fLeft, fRight);
}

void Explosion::boomT(Point pT)
{
   pT.setY(pT.getY() + 0.5);
   bool fBottom = false;
   bool fLeft = false;
   bool fRight = false;
   drawLanderFlames(pT, fBottom, top, fLeft, fRight);
}

void Explosion::boomL(Point pL)
{
   pL.setY(pL.getY() - 10);
   pL.setX(pL.getX() + 1.5);
   bool fTop = false;
   bool fBottom = false;
   bool fRight = false;
   drawLanderFlames(pL, fBottom, fTop, left, fRight);
}

void Explosion::boomR(Point pR)
{
   pR.setY(pR.getY() - 10);
   pR.setX(pR.getX() - 0.5);
   bool fTop = false;
   bool fLeft = false;
   bool fBottom = false;
   drawLanderFlames(pR, fBottom, fTop, fLeft, right);
}

void Explosion::boom(Point p)
{
   bottom = true;
   top = true;
   left = true;
   right = true;
   
   for (int i = 0; i < 5000; i++)
   {
      boomB(p);
      boomT(p);
      boomL(p);
      boomR(p);
   }
}
