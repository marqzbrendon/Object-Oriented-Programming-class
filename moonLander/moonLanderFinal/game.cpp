/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "ground.h"
#include "lander.h"

/******************************************
 * GAME :: JUST LANDED
 * Did we land successfully?
 ******************************************/
bool Game :: justLanded() const
{
   bool landed = false;
   
   Point platformCenter = ground.getPlatformPosition();
   int width = ground.getPlatformWidth();

   float xDiff = lander.getPoint().getX() - platformCenter.getX();
   float yDiff = lander.getPoint().getY() - platformCenter.getY();

   float margin = width / 2.0;
   
   if (fabs(xDiff) < margin)
   {
      // between edges
      
      if (yDiff < 4 && yDiff >= 0)
      {
         // right above it
         
         if (fabs(lander.getVelocity().getDx()) < 3 && fabs(lander.getVelocity().getDy()) < 3)
         {
            // we're there!
            landed = true;
         }
      }
   }
   
   return landed;
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   if (lander.isAlive() && !lander.isLanded())
   {
      // advance the lander
      lander.applyGravity(GRAVITY_AMOUNT);
      lander.advance();
   
      // check for crash
      if (!ground.isAboveGround(lander.getPoint()))
      {
         lander.setAlive(false);
      }
   
      // check for just landed
      if (justLanded())
      {
         lander.setLanded(true);
      }
   }
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   if (lander.isAlive() && !lander.isLanded())
   {   
      if (ui.isDown())
      {
         lander.applyThrustBottom();
      }
      
      if (ui.isLeft())
      {
         lander.applyThrustLeft();
      }
      
      if (ui.isRight())
      {
         lander.applyThrustRight();
      }
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   // draw the main lander
   lander.draw();

   // Draws the stars
   Point position;
   Point position2;
   Point position3;
   Point position4;
   Point position5;
   position.setX(random(-200, 200));
   position.setY(random(25, 200));

   position2.setX(random(-200, 200));
   position2.setY(random(25, 200));

   position3.setX(random(-200, 200));
   position3.setY(random(25, 200));

   position4.setX(random(-200, 200));
   position4.setY(random(25, 200));

   position5.setX(random(-200, 200));
   position5.setY(random(25, 200));
   
   drawDot(position);
   drawDot(position2);
   drawDot(position3);
   drawDot(position4);
   drawDot(position5);
   
   // draw Lander 1 on screen
   drawLander(landerLocation);

   // draw lander 2 on screen
   drawLander(landerLocation2);

   // draw lander 3 on screen
   drawLander(landerLocation3);

   // draw the extra landers flames whenever the player is alive
   if (lander.isAlive())
   {
	   drawLanderFlames(landerLocation3, true, false, false);
	   drawLanderFlames(landerLocation, true, false, false);
	   drawLanderFlames(landerLocation2, true, false, false);
   }


   if (lander.isLanded())
   {
      drawText(Point(), "You have successfully landed!");

	  // extra landers take off
	  landerLocation.setY(landerLocation.getY() + 10);
	  landerLocation2.setY(landerLocation2.getY() + 10);
	  landerLocation3.setY(landerLocation3.getY() + 10);
   }
   
   if (!lander.isAlive())
   {
      drawText(Point(), "You have crashed!");

	  // star is drawn
	  drawSacredBird(lander.getPoint(), 75);

	  // extra landers fall
	  landerLocation.setY(landerLocation.getY() - 10);
	  landerLocation2.setY(landerLocation2.getY() - 10);
	  landerLocation3.setY(landerLocation3.getY() - 10);

   }
   
   if (lander.canThrust())
   {
      drawLanderFlames(lander.getPoint(), ui.isDown(), ui.isLeft(), ui.isRight());
   }
   
   Point fuelLocation;
   fuelLocation.setX(topLeft.getX() + 5);
   fuelLocation.setY(topLeft.getY() - 5);
   
   drawNumber(fuelLocation, lander.getFuel());

   // draw ground
   ground.draw();
}

