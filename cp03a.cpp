/***********************************************************************
* Program:
*    Checkpoint 03a, Exceptions  
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

bool validate(int num)
{
	if (num > 100)
	{
		cout << "Error: The number cannot be greater than 100.\n";
		return false;
	}

	else if (num < 0)
	{		
		cout << "Error: The number cannot be negative.\n";
		return false;
	}

	else if (num % 2 == 1)
	{	
		cout << "Error: The number cannot be odd.\n";	
		return false;
	}
	
	else 

		return true;
}

int prompt()
{
	cout << "Enter a number: ";
	int num;
	cin >> num;

	bool check = validate(num);

	if (check == false)
	{
		return -1;
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

	if (num < 0)
	{
		return 0;
	}

	cout << "The number is "
	     << num
	     << ".\n";

   return 0;
}
