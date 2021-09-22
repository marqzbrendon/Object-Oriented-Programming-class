/***********************************************************************
* Program:
*    Checkpoint 03b,   
*    Brother Comeau, CS165
* Author:
*    Brendon Marques
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>

using namespace std;

int prompt()
{
   cout << "Enter a number: ";
   int num;
   cin >> num;

   while(cin.fail())
   {
      cin.clear();      \
      cin.ignore(256, '\n');

      cout << "Invalid input.\n"
           << "Enter a number: ";

      cin >> num;      
   }

   return num;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   int num = prompt();

   cout << "The number is "
        << num
        << ".\n";

   return 0;
}
