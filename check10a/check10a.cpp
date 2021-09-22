/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Comeau, CS165
* Author:
*    Brendon Marques
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/
#include <iostream>
#include <vector>

using namespace std;



/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   vector<int> ints;

   int n = 1;
   
   while (n != 0)
   {
      cout << "Enter int: ";
      cin >> n;

      if (n != 0)
      {
         ints.push_back(n);
      }
   }

   cout << "Your list is:\n";

   for (int i = 0; i < ints.size(); i++)
   {
      cout << ints[i] << endl;
   }

   cout << endl;

   vector<string> words;

   string w = "aaa";

   while (w != "quit")
   {
      cout << "Enter string: ";
      cin >> w;


      if (w != "quit")
      {
         words.push_back(w);
      }
   }

   cout << "Your list is:\n";


   for (int i = 0; i < words.size(); i++)
   {
      cout << words[i] << endl;
   }


   return 0;
}


