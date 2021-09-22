#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
private:
   float dx;
   float dy;

public:
   /**************************
    * Getters and Setters
    **************************/
   float getDx() const { return dx; }
   float getDy() const { return dy; }

   void setDx(float dx) { this->dx = dx; }
   void setDy(float dy) { this->dy = dy; }

   /**************************
    * Public member functions
    **************************/
   void prompt();
   void display() const;

    /**************************
    * Friend operators
    **************************/
   friend Velocity operator - (const Velocity &lhs, const Velocity &rhs)
   {
    Velocity temp;

    temp.dx = (lhs.dx - rhs.dx);
    temp.dy = (lhs.dy - rhs.dy);

    return temp;
   }

   friend void operator -= (Velocity &lhs, const Velocity &rhs)
   {
      lhs.dx = (lhs.dx - rhs.dx);
      lhs.dy = (lhs.dy - rhs.dy);
   }
};

Velocity operator + (const Velocity &lhs, const Velocity &rhs);
void operator += (Velocity &lhs, const Velocity &rhs);

#endif
