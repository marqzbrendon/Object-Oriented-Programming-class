###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Comeau, CS165
# Author:
#     Brendon Marques
# Summary:
#     This is the final project for the Moon Lander game. 
# 		The game follows the basic rules, appying gravity and
#		inertia. Extra features are explained below.
# Above and Beyond
#     The extra features in this game are:
#			- Stars are drawn on the top of the screen. It is a 
#			  set of 5 stars that are drawn at a random place 
#	        on the screen every time the function is called.
#
#			- Three extra landers are drawn in random places of 
#          the screen. Everytime the player lands succesfully,
#			  the lander take off towards the space. When the 
#			  player crashes, the landers thruttles shut down and
#			  the landers fall.
#
#			- When the player crashes, a spinning red star is 
#			  drawn at the crashing location. 
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o $(LFLAGS)
	tar -j -cf moonLanderMS.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -c driver.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
lander.o: lander.cpp lander.h point.h velocity.h uiDraw.h
	g++ -c lander.cpp

velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
