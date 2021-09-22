#include "robot.h"
#include <iostream>
using namespace std;

/************************************
 * Function: Display
 * Purpose: Displays the robot.
 ************************************/
void Robot :: display() const
{
   position.display();
   cout << " - Energy: " << getEnergy();
}

void Robot :: setEnergy(int energy)
{
   if (energy < 0)
   {
      energy = 0;
   }

   this->energy = energy;
}

int Robot :: getEnergy() const
{
   return energy;
}

void Robot :: setPosition(Point p)
{
   position = p;
}

void Robot :: moveUp()
{
   if (position.getX() == 3 && position.getY() == 3 ||
       position.getX() == 4 && position.getY() == 4 ||
       position.getX() == 6 && position.getY() == 6)
   {
      cout << "OPS! You got trapped!\n";
      setEnergy(energy - 100);
   }

   else if (position.getY() == 10 || energy <= 10)
   {
      cout << "Cannot move up.";
   }
   
   else
   {
      position.setYUp();
      setEnergy(energy - 10);
   }
}

void Robot :: moveDown()
{
   if (position.getX() == 3 && position.getY() == 3 ||
       position.getX() == 4 && position.getY() == 4 ||
       position.getX() == 6 && position.getY() == 6)
   {
      cout << "OPS! You got trapped!\n";
      setEnergy(energy - 100);
   }

   else if (position.getY() == 1 || energy <= 10)
   {
      cout << "Cannot move down.";
   }
   
   else
   {
      position.setYDown();
      setEnergy(energy - 10);
   }
}

void Robot :: moveLeft()
{
   if (position.getX() == 3 && position.getY() == 3 ||
       position.getX() == 4 && position.getY() == 4 ||
       position.getX() == 6 && position.getY() == 6)
   {
      cout << "OPS! You got trapped!\n";
      setEnergy(energy - 100);
   }

   else if (position.getX() == 1 || energy <= 10)
   {
      cout << "Cannot move left.";
   }
   
   else
   {
      position.setXLeft();
      setEnergy(energy - 10);
   }
}

void Robot :: moveRight()
{
   if (position.getX() == 3 && position.getY() == 3 ||
       position.getX() == 4 && position.getY() == 4 ||
       position.getX() == 6 && position.getY() == 6)
   {
      cout << "OPS! You got trapped!\n";
      setEnergy(energy - 100);
   }

   else if (position.getX() == 10 || energy <= 10)
   {
      cout << "Cannot move right.";
   }
   
   else
   {
      position.setXRight();
      setEnergy(energy - 10);
   }
}  

void Robot :: fireLaser()
{
   if (energy < 25)
   {
      cout << "Not enough energy :(\n";
   }

   else
   {
      cout << "Pew! Pew!\n";
      setEnergy(energy - 25);
   }
}
