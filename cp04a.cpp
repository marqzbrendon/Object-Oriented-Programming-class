/***********************************************************************
* Program:
*    Checkpoint 04a, Classes  
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

class Book
{
private:
	string title;
	string author;

public:
	void prompt()
	{
		cout << "Title: ";
		getline(cin, title);
		cout << "Author: ";
		getline(cin, author);
	}

	void display()
	{
		cout << "\"" << title << "\" "
			  << "by " << author
			  << endl;
	}
};

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
	Book book;

	book.prompt();
	book.display();
   return 0;
}
