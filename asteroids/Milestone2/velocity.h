#ifndef VELOCITY_H
#define VELOCITY_H


// Put your velocity class here, or overwrite this file with your own
// velocity class from the previous project
class Velocity
{
private:
   // Private variables
   float dx;
   float dy;
public:

   // Methods
   float getDx();
   float getDy();
   void setDx(float dx);
   void setDy(float dy);

   // Constructors
   Velocity()
   {
      dx = 1;
      dy = 1;
   }

   Velocity(float dx, float dy)
   {
      this->dx = dx;
      this->dy = dy;
   }

};

#endif /* velocity_h */
