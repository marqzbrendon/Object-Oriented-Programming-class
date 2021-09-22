###############################################################
# Program:
#     Project 13, Asteroids
#     Brother Comeau, CS165
# Author:
#     Brendon Marques
# Summary:
#     Final Asteroids project. 
#		
# Above and Beyond
#
#		Features:
#
#			1. The game has 3 states: 
#				- Welcome state: initial screen message when the
#					game is launched. It will prompt the player
#					to hip the key 'arrow down' to start the game.
#
#				- Game state: the state of the game while in play.
#
#				- Play Again state: when the player wins or loses,
#					a message will be displayed prompting the user
#					to hit the key 'arrow down' to play again.
#     
#			2. You lost message: it is displayed when the user
#				crashes the ship.
#
#			3. Victory message: a 'VICTORY!' message appears next
#				to the ship when the player kills all the rocks.
#				The message moves with the ship.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObjects.o ship.o bullet.o rocks.o largeRock.o mediumRock.o smallRock.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObjects.o ship.o bullet.o rocks.o largeRock.o mediumRock.o smallRock.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObjects.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

driver.o: driver.cpp game.h
	g++ -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h flyingObjects.h bullet.h rocks.h ship.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

flyingObjects.o: flyingObjects.cpp flyingObjects.h point.h velocity.h uiDraw.h
	g++ -c flyingObjects.cpp

ship.o: ship.cpp ship.h flyingObjects.h point.h velocity.h uiDraw.h
	g++ -c ship.cpp

bullet.o: bullet.cpp bullet.h flyingObjects.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

rocks.o: rocks.cpp rocks.h flyingObjects.h point.h velocity.h uiDraw.h
	g++ -c rocks.cpp

largeRock.o: largeRock.cpp largeRock.h rocks.h
	g++ -c largeRock.cpp

mediumRock.o: mediumRock.cpp mediumRock.h rocks.h
	g++ -c mediumRock.cpp

smallRock.o: smallRock.cpp smallRock.h rocks.h
	g++ -c smallRock.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
