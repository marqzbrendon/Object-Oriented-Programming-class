#ifndef POINT_H
#define POINT_H

class Point
{
private:
   int x;
   int y;

public:
   void display() const;
   void setX(int x);
   void setY(int y);
   int getX() const;
   int getY() const;
   int setYUp();
   int setYDown();
   int setXLeft();
   int setXRight();

   Point()
   {
      x = 5;
      y = 5;
   }

   Point (int x, int y)
   {
      if (x < 1)
      {
         x = 1;
      }

      else if (x > 10)
      {
         x = 10;
      }

      if (y < 1)
      { 
         y = 1;
      }

      else if (y > 10)
      {
         y = 10;
      }

         this->x = x;
         this->y = y;
   }

};

#endif
