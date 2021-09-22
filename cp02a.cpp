/***********************************************************************
* Program:
*    Checkpoint 02a, Structs  
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


struct user
{
	string firstName;
	string lastName;
	int idNumber;
};

user promptInfo()
{
	user temp;
	cout << "Please enter your first name: ";
	cin >> temp.firstName;

	cout << "Please enter your last name: ";
	cin >> temp.lastName;

	cout << "Please enter your id number: ";
	cin >> temp.idNumber;

	return temp;
}

void display(user info)
{
	cout << endl 
		 <<	"Your information:\n"
	     <<	info.idNumber
	     << " - "
	     << info.firstName
	     << " "
	     << info.lastName
	     << endl;
}	

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
	user info;
	info = promptInfo();
	display(info);



   return 0;
}
