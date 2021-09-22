/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"
#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"

#include <vector>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game::Game(Point tl, Point br)
   : topLeft(tl), bottomRight(br)
{
   // Set up the initial conditions of the game
   create = true;
   state = 1;
   count = 0;
   noAsteroids = false;
   prevState = 1;

}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{

}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game::advance()
{
   if (ship.isAlive())
   {
      advanceBullets();
   }

   advanceRocks();
   
   if (ship.isAlive())
   {
      advanceShip();
   }

   handleCollisions();
   cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game::advanceBullets()
{
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i].advance(bottomRight, topLeft);
      }
   }
}

void Game::advanceShip()
{
   ship.advance(bottomRight, topLeft);
   ship.checkAngle();
}

/**************************************************************************
 * GAME :: ADVANCE ROCKS
 **************************************************************************/
void Game::advanceRocks()
{
   if (create)
   {
      // create the initial 5 large rocks in locations
      // that are not in the middle of the screen
      for (int i = 0; i < 5; i++)
      {
         int type = random(1, 5);

         Point p;

         if (type == 1)
         { 
            p.setX(random(-175, -50));
            p.setY(random(-175, 175));
         }
         if (type == 2)
         {
            p.setX(random(-175, 175));
            p.setY(random(50, 175));
         }
         if (type == 3)
         {
            p.setX(random(50, 175));
            p.setY(random(-175, 175));
         }
         if (type == 4)
         {
            p.setX(random(-175, 175));
            p.setY(random(-175, -50));
         }
         createRocks(0, p);
      }
   }

   create = false;

   // we have rocks, make sure it's alive
   for (int i = 0; i < rocks.size(); i++)
   {
      if (rocks[i].isAlive())
      {
         // move it forward
         rocks[i].advance(bottomRight, topLeft);
      }
   }

   for (int i = 0; i < medium.size(); i++)
   {
      if (medium[i].isAlive())
      {
         // move it forward
         medium[i].advance(bottomRight, topLeft);
      }
   }

   for (int i = 0; i < small.size(); i++)
   {
      if (small[i].isAlive())
      {
         // move it forward
         small[i].advance(bottomRight, topLeft);
      }
   }


}

/**************************************************************************
 * GAME :: CREATE ROCK
 * Create a rock according to the rules of the game.
 **************************************************************************/
void Game::createRocks(int type, Point p)
{
   if (type == 0)
   {
      LargeRock newRock;
      newRock.position = p;
      rocks.push_back(newRock);
   }
   else if (type == 1)
   {
      MediumRock newRock;
      newRock.position = p;
      medium.push_back(newRock);
   }
   else if (type == 2)
   {
      SmallRock newRock;
      newRock.position = p;
      small.push_back(newRock);
   }
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game::isOnScreen(const Point& point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game::handleCollisions()
{
   // now check for a hit (if it is close enough to any live bullets)
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, see if its too close
         for (int j = 0; j < rocks.size(); j++)
         {
            // check if the bird is at this point (in case it was hit)
            if (rocks[j].isAlive())
            {
               // BTW, this logic could be more sophisiticated, but this will
               // get the job done for now...
               if (bullets[i].isAlive()
                   && fabs(bullets[i].getPoint().getX() - rocks[j].getPoint().getX()) < CLOSE_ENOUGH_LARGE
                   && fabs(bullets[i].getPoint().getY() - rocks[j].getPoint().getY()) < CLOSE_ENOUGH_LARGE)
               {
               // the bullet is dead as well
               bullets[i].kill();

               // a bullet hit a large rock! Destroy the rock, the bullet, and create new ones
               rocks[j].kill();
               for (int i = 0; i < 2; i++)
               {
                  createRocks(1, rocks[j].getPoint());
               }

               createRocks(2, rocks[j].getPoint());
               }

               // does a similar thing as the above code, but uses the getClosestDistance() function instead
               // this is helpful to increase the precision of a hit
               if (getClosestDistance(rocks[j], bullets[i]) <= CLOSE_ENOUGH_LARGE)
               {
                  // the bullet is dead as well
                  bullets[i].kill();

                  //we have a hit!
                  rocks[j].kill();
                  for (int i = 0; i < 2; i++)
                  {
                     createRocks(1, rocks[j].getPoint());
                  }

                  createRocks(2, rocks[j].getPoint());
               }
            }
         }

         // do the same thing for medium rocks
         for (int j = 0; j < medium.size(); j++)
         {
            if (medium[j].isAlive())
            {
               if (bullets[i].isAlive()
                   && fabs(bullets[i].getPoint().getX() - medium[j].getPoint().getX()) < CLOSE_ENOUGH_MEDIUM
                   && fabs(bullets[i].getPoint().getY() - medium[j].getPoint().getY()) < CLOSE_ENOUGH_MEDIUM)
               {
                  medium[j].kill();
                  for (int i = 0; i < 2; i++)
                  {
                     createRocks(2, medium[j].getPoint());
                  }

                  bullets[i].kill();
               }

               if (getClosestDistance(medium[j], bullets[i]) <= CLOSE_ENOUGH_MEDIUM)
               {
                  //we have a hit!
                  medium[j].kill();
                  for (int i = 0; i < 2; i++)
                  {
                     createRocks(2, medium[j].getPoint());
                  }

                  // the bullet is dead as well
                  bullets[i].kill();
               }
            }
         }

         // do the same thing for small rocks
         for (int j = 0; j < small.size(); j++)
         {
            if (small[j].isAlive())
            {
               if (bullets[i].isAlive()
                   && fabs(bullets[i].getPoint().getX() - small[j].getPoint().getX()) < CLOSE_ENOUGH_SMALL
                   && fabs(bullets[i].getPoint().getY() - small[j].getPoint().getY()) < CLOSE_ENOUGH_SMALL)
               {
                  small[j].kill();

                  bullets[i].kill();
               }

               if (getClosestDistance(small[j], bullets[i]) <= CLOSE_ENOUGH_SMALL)
               {
                  small[j].kill();

                  bullets[i].kill();
               }
            }
         }
      }
   }

   // if ship collides to large rock
   for (int j = 0; j < rocks.size(); j++)
   {
      if (fabs(ship.getPoint().getX() - rocks[j].getPoint().getX()) < CLOSE_ENOUGH_LARGE
          && fabs(ship.getPoint().getY() - rocks[j].getPoint().getY()) < CLOSE_ENOUGH_LARGE)
      {
      // the ship is dead
         ship.kill();
      }

      // using getClosestDistance()
      if (getClosestDistance(rocks[j], ship) <= CLOSE_ENOUGH_LARGE)
      {
         ship.kill();
      }
   }

   // if ship collides to medium rock
   for (int j = 0; j < medium.size(); j++)
   {
      if (fabs(ship.getPoint().getX() - medium[j].getPoint().getX()) < CLOSE_ENOUGH_MEDIUM
          && fabs(ship.getPoint().getY() - medium[j].getPoint().getY()) < CLOSE_ENOUGH_MEDIUM)
      {
         ship.kill();
      }

      if (getClosestDistance(medium[j], ship) <= CLOSE_ENOUGH_MEDIUM)
      {
         ship.kill();
      }
   }

   // if ship collides to small rock
   for (int j = 0; j < small.size(); j++)
   {
      if (fabs(ship.getPoint().getX() - small[j].getPoint().getX()) < CLOSE_ENOUGH_SMALL
          && fabs(ship.getPoint().getY() - small[j].getPoint().getY()) < CLOSE_ENOUGH_SMALL)
      {
         ship.kill();
      }
      if (getClosestDistance(small[j], ship) <= CLOSE_ENOUGH_SMALL)
      {
         ship.kill();
      }
   }
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate bird)
 **************************************************************************/
void Game::cleanUpZombies()
{

   // Look for dead bullets
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;

      if (!bullet.isAlive())
      {
         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }

   // Look for dead large rocks
   vector<LargeRock>::iterator it = rocks.begin();
   while (it != rocks.end())
   {
      LargeRock r = *it;

      if (!r.isAlive())
      {
         // remove from list and advance
         it = rocks.erase(it);
      }
      else
      {
         it++; // advance
      }
   }

   // Look for dead medium rocks
   vector<MediumRock>::iterator it2 = medium.begin();
   while (it2 != medium.end())
   {
       MediumRock r = *it2;

      if (!r.isAlive())
      {
         // remove from list and advance
         it2 = medium.erase(it2);
      }
      else
      {
         it2++; // advance
      }
   }

   // Look for dead small rocks
   vector<SmallRock>::iterator it3 = small.begin();
   while (it3 != small.end())
   {
      SmallRock r = *it3;

      if (!r.isAlive())
      {
         // remove from list and advance
         it3 = small.erase(it3);
      }
      else
      {
         it3++; // advance
      }
   }

}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game::handleInput(const Interface& ui)
{
   // Change the direction of the ship
   if (ui.isLeft())
   {
      ship.moveLeft();
   }

   if (ui.isRight())
   {
      ship.moveRight();
   }

   // accelerate the ship
   if (ui.isUp())
   {
      ship.accelerate();
      if (ship.isAlive())
      {
         ship.setThrust(true);
      }
      else
      {
         ship.setThrust(false);
      }
   }
   // stop displaying thrust flame
   else if (!ui.isUp())
   {
      ship.setThrust(false);
   }

   // Check for "Spacebar"
   if (ui.isSpace())
   {
      if (ship.isAlive())
      {
         Bullet newBullet;
         newBullet.fire(ship.getPoint(), ship.getAngle(), ship.getSpeed());
         bullets.push_back(newBullet);
      }
   }

   // start a new game or start after dying/winning
   if (ui.isDown())
   {
      // change the state to 2
      state = 2;

      // if the game is over and the user wants to play again,
      // set the original conditions of the game for a new game
      if (prevState == 3)
      {
         setNewGame();
      }
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game::draw(const Interface& ui)
{
   // draw the rocks
   for (int i = 0; i < rocks.size(); i++)
   {
      rocks[i].draw();
   }

   for (int i = 0; i < medium.size(); i++)
   {
      medium[i].draw();
   }

   for (int i = 0; i < small.size(); i++)
   {
      small[i].draw();
   }

   // draw the ship
   if (state != 1)
   {
      ship.draw();
   }

   // draw the bullets, if they are alive
   if (ship.isAlive())
   {
      for (int i = 0; i < bullets.size(); i++)
      {
         if (bullets[i].isAlive())
         {
            bullets[i].draw();
         }
      }
   }


   // count the number of alive asteroids to know if player won the game
   if (ship.isAlive() && create == false)
   {
      int count = 0;

      for (int i = 0; i < rocks.size(); i++)
      {
         if (rocks[i].isAlive())
         {
            count++;
         }
      }

      for (int i = 0; i < medium.size(); i++)
      {
         if (medium[i].isAlive())
         {
            count++;
         }
      }

      for (int i = 0; i < small.size(); i++)
      {
         if (small[i].isAlive())
         {
            count++;
         }
      }

      if (count < 1)
      {
         noAsteroids = true;
         state = 3;
      }

   }

   // Display YOU_LOST! message
   if (!ship.isAlive() && create == false)
   {
      char ca[12] = "YOU LOST :(";
      Point center;
      center.setX(-30);
      center.setY(0);
      drawText(center, ca);

      // display play again message
      prevState = 3;
      state = 3;
      char pa[39] = "PRESS THE DOWN ARROW KEY TO PLAY AGAIN";
      Point below;
      below.setX(-145);
      below.setY(-20);
      drawText(below, pa);
   }

   // display VICTORY message
   if (ship.isAlive() && noAsteroids == true)
   {
         char ca[10] = "VICTORY!";

         drawText(ship.getPoint(), ca);

         prevState = 3;
         state = 3;

         // display play again message
         char pa[39] = "PRESS THE DOWN ARROW KEY TO PLAY AGAIN";
         state = 3;
         Point center;
         center.setX(-145);
         center.setY(0);
         drawText(center, pa);
   }

   // Display WELCOME message
   if (state == 1)
   {
      char welcome[22] = "WELCOME TO ASTEROIDS!";
      Point center;
      center.setX(-80);
      center.setY(10);
      drawText(center, welcome);

      // display press key to play
      char welcome2[33] = "PRESS THE DOWN ARROW KEY TO PLAY";
      Point below;
      below.setX(-122);
      below.setY(-20);
      drawText(below, welcome2);
   }

}

/*********************************************
 * GAME :: SET NEW GAME
 * Sets all the original conditions of the game
 * to start a new one.
 *********************************************/
void Game::setNewGame()
{
   prevState = 2;
   create = true;
   noAsteroids = false;
   count = 0;
   ship.setAlive(true);
   ship.setPoint(Point());
   Velocity newSpeed;
   newSpeed.setDx(0);
   newSpeed.setDy(0);
   ship.setVelocity(newSpeed);
   ship.setAngle(0);

   // kill all remaining rocks to create new ones
   for (int i = 0; i < rocks.size(); i++)
   {
      if (rocks[i].isAlive())
      {
         rocks[i].kill();
      }
   }

   for (int i = 0; i < medium.size(); i++)
   {
      if (medium[i].isAlive())
      {
         medium[i].kill();
      }
   }

   for (int i = 0; i < small.size(); i++)
   {
      if (small[i].isAlive())
      {
         small[i].kill();
      }
   }

   // kill all remaining bullets as well
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].kill();
      }
   }
}



// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;


// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
float Game :: getClosestDistance(FlyingObjects &obj1, FlyingObjects &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}

void Game::setCreate(bool create)
{
   this->create = create;
}

void Game::setState(int state)
{
   this->state = state;
}

void Game::setCount(int count)
{
   this->count = count;
}

void Game::setNoAsteroids(bool noAsteroid)
{
   this->noAsteroids = noAsteroids;
}


