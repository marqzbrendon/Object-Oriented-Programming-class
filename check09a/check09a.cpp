/***********************************************************************
* Program:
*    Checkpoint 09a, Virtual Functions
*    Brother Comeau, CS165
* Author:
*    Brendon Marques
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your classes here
class Car
{
private:


protected:

   string name;

public:

   string getName() { return name; };
   void setName(string n) { name = n; };
   virtual string getDoorSpecs() { return "Unknown doors"; };

   Car()
   {
      name = "Unknown model";
   }

};

class Civic : public Car
{
private:

public:

   string getDoorSpecs() { return "4 doors"; };

   Civic()
   {
      name = "Civic";
   }

};

class Odyssey : public Car
{
private:

public:

   string getDoorSpecs() { return "2 front doors, 2 sliding doors, 1 tail gate"; };

   Odyssey()
   {
      name = "Odyssey";
   }

};


class Ferrari : public Car
{
private:

public:

   string getDoorSpecs() { return "2 butterfly doors"; };

   Ferrari()
   {
      name = "Ferrari";
   }

};



/**********************************************************************
 * Function: attachDoors
 * Purpose: This function can accept any type of Car object. It will
 *  call the appropriate functions to display the name and the doors info.
 ***********************************************************************/

// TODO: Include your attachDoors function here
void attachDoors(Car& model)
{
   Car *pModel = &model;

   cout << "Attaching doors to "
        << pModel->getName()
        << " - "
        << pModel->getDoorSpecs()
        << endl;
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // You should not change main

   Civic civic;
   Odyssey odyssey;
   Ferrari ferrari;

   attachDoors(civic);
   attachDoors(odyssey);
   attachDoors(ferrari);

   return 0;
}


