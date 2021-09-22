#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObjects.h"

// Define the following classes here:
//   Rock
class Rock : public FlyingObjects
{
private:

public:

   Rock()
   {
      position.setX(random(-150, 150));
      position.setY(random(-150, 150));

      speed.setDx(random(-0.5, 0.5));
      speed.setDy(random(-0.5, 0.5));

   }

   void draw();
};
//   BigRock
//   MediumRock
//   SmallRock



#endif /* rocks_h */
