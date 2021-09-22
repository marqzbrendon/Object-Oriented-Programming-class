/***********************************************************************
* Program:
*    Checkpoint 0xx, XXXXXXXXXX  
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
#include <string>

using namespace std;

struct Scripture
{
	string book[3];
	int chapter[3];
	int verse[3];
};

struct Insight
{
	Scripture scripture;
	string insight[3];	
};

void displayInsight(int i, Insight ref)
{
	cout << "Insight: "
	     << ref.insight[i]
		  << endl;
}

void displayScripture(Insight ref)
{
	for (int i = 0; i < 3; i++)
	{
		cout << ref.scripture.book[i]
   		  << " "
     		  << ref.scripture.chapter[i]
	  		  << ":"
	  		  << ref.scripture.verse[i]
	  		  << endl;

	  		  displayInsight(i, ref);

	  		  cout << endl;
	}
}

string promptInsight()
{
		cout << "Insight: ";
		string insight;
		getline(cin, insight);

		cout << endl;

		return insight;
}

void promptScripture(Insight &reference)
{
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Book: ";
		getline(cin, reference.scripture.book[i]);

		cout << "Chapter: ";
		cin >> reference.scripture.chapter[i];

		cout << "Verse: ";
		cin >> reference.scripture.verse[i];

		cin.ignore();
		
		reference.insight[i] = promptInsight();
	}	 
}


/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
	Insight reference;

	promptScripture(reference);

	displayScripture(reference);

   return 0;
}
