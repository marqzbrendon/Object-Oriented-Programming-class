	###############################################################
# Program:
#     Project 09, Skeet
#     Brother Comeau, CS165
# Author:
#     Brendon Marques
# Summary:
#    This is the working version with no extra features. I'm
#    turning this in in case I'm not able to get my features
#    to work.
# Above and Beyond
#     ...
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o bullet.o bird.o flyingObjects.o velocity.o standardBird.o toughBird.o sacredBird.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o bullet.o bird.o flyingObjects.o velocity.o standardBird.o toughBird.o sacredBird.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h bird.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
bullet.o: bullet.cpp bullet.h flyingObjects.h point.h
	g++ -c bullet.cpp

bird.o: bird.cpp bird.h flyingObjects.h
	g++ -c bird.cpp

flyingObjects.o: flyingObjects.cpp flyingObjects.h point.h velocity.h uiDraw.h
	g++ -c flyingObjects.cpp

velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

standardBird.o: standardBird.cpp standardBird.h bird.h
	g++ -c standardBird.cpp

sacredBird.o: sacredBird.cpp sacredBird.h bird.h
	g++ -c sacredBird.cpp

toughBird.o: toughBird.cpp toughBird.h bird.h
	g++ -c toughBird.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
