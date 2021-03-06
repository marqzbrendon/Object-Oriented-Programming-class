/***********************************************************************
* Program:
*    Checkpoint 01a, C++ Basics          (e.g. Checkpoint 01a, review)  
*    Brother Comeau, CS165
* Author:
*    Brendon Marques
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // declaring variables
   string name;
   int age;

   
   // display initial message
   cout << "Hello CS 165 World!" << endl;

   
   // ask questions
   cout << "Please enter your first name: ";
   cin >> name;

   cout << "Please enter your age: ";
   cin >> age;


   // display final message
   cout << endl
        << "Hello " << name
        << ", you are " << age
        << " years old.\n";
   
   return 0;
}
