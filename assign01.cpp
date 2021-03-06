/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy            
*    Brother Comeau, CS165
* Author:
*    Brendon Marques
* Summary: 
*    This program will compare the DNA sequence of different people
*    to determine the match percentage between them. The user will
*    first be prompted to enter his/her DNA sequence. Then, the
*    program will ask for a number of potential relatives. The user
*    will then provide the DNA sequence for each potential relative.
*    Finally, the program will display the compatibility between the
*    user's DNA sequence and the potential relative.
*    
*
*    Estimated:  0.0 hrs   
*    Actual:     2.0 hrs
*      The only issue I had was to convert the DNA sequences to
*      uppercase. For some reason the toupper() function did not work.
*      However, I was able to find a work-around on google using the
*      library "bits/stdc++.h".
************************************************************************/
#include <string>
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;


/**********************************************************************
 * promptOwnDna()
 *
 * This function will prompt the user for his or her own DNA sequence.
 ***********************************************************************/
string promptOwnDna()
{
   // variable
   string dna;

   // prompt for DNA sequence
   cout << "Enter your DNA sequence: ";
   cin >> dna;

   // make it all uppercase
   transform(dna.begin(), dna.end(), dna.begin(), ::toupper);

   // return DNA sequence
   return dna;
}


/**********************************************************************
 * promptRelNumber()
 *
 * This function will prompt the user for the number of potential
 * relatives that he or she will like to compare to.
 ***********************************************************************/
int promptRelNumber()
{
   // variable
   int relNumber;

   // prompt for the number of potential relatives
   cout << "Enter the number of potential relatives: ";
   cin >> relNumber;
   cout << endl;

   // return the number of potential relatives
   return relNumber;
}


/**********************************************************************
 * promptRelNames()
 *
 * Will prompt for the names of the potential relatives and storage them
 * in a 2 dimensional array of strings.
 ***********************************************************************/
void promptRelNames(string relNames[], int relNumber)
{
   // for loop to prompt for the names and storage them
   for (int i = 0; i < relNumber; i++)
   {
      cout << "Please enter the name of relative #"
           << i + 1
           << ": ";

      cin >> relNames[i];
   }

   // jump a line once the loop is finished
   cout << endl;
}


/**********************************************************************
 * promptRelDna()
 *
 * Prompts for the DNA sequence of the potential relatives and storage
 * them in a 2 dimensional array.
 ***********************************************************************/
void promptRelDna(string relDna[], string relNames[], int relNumber)
{
   // for loop to prompt for the DNA sequences
   // and storage them in the array
   for (int i = 0; i < relNumber; i++)
   {  
      cout << "Please enter the DNA sequence for "
           << relNames[i]
           << ": ";

      cin >> relDna[i];

      // change all DNA sequences to uppercase
      transform(relDna[i].begin(), relDna[i].end(),
                relDna[i].begin(), ::toupper);
   }

   // jump a line
   cout << endl;
}


/**********************************************************************
 * compareDna()
 *
 * This function will compare the user's DNA sequence with the ones
 * from their potential relatives
 ***********************************************************************/
void compareDna(int matches[], string ownDna, string relDna[], int relNumber)
{
   // loop to go through both arrays (users and relatives)
   // and compare them
   for (int i = 0; i < relNumber; i++)
   {
      int match = 0;

      for (int j = 0; j < 10; j++)
      {
         if (ownDna[j] == relDna[i][j])
         {
            // add 10 every time there is a match
            match += 10;
         }
      }

      // storage the total match in the array of ints
      matches[i] = match;
   }
}


/**********************************************************************
 * display()
 *
 * This function displays the final results to the user.
 ***********************************************************************/
void display(string relNames[], int matches[], int relNumber)
{
   // loop through the arrays o display the matching percentage
   for (int i = 0; i < relNumber; i++)
   {
      cout << "Percent match for "
           << relNames[i]
           << ": "
           << matches[i]
           << "%\n";
   }
}

/**********************************************************************
 * main()
 *
 * It is the driver of the program. Its primary role is to determine
 * where the program will start executing, call other functions, and
 * kill the program once it is completely finished.
 ***********************************************************************/
int main()
{
   // variables
   string relNames[50];
   string relDna[50];
   int matches[50];

   // prompt for user's own DNA sequence
   string ownDna = promptOwnDna();

   // prompt number of potential relatives
   int relNumber = promptRelNumber();

   // prompt potential relatives names
   promptRelNames(relNames, relNumber);

   // prompt potential relatives DNA sequences
   promptRelDna(relDna, relNames, relNumber);

   // compare the DNA sequences
   compareDna(matches, ownDna, relDna, relNumber);

   // display the final results
   display(relNames, matches, relNumber);

   // amen to that, brother
   return 0;
}
