/**********************************************************************
 * File: ta03.cpp
 * Author: Brendon Marques
 *
 * Description: Use this file as a starting point for Team Activity 03.
 *    You do not need to "submit" your code, but rather, answer the
 *    questions in the I-Learn assessment.
 **********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/***********************************************************************
 * Struct: Scripture
 * Description: Holds the reference to a scripture (book, chapter, verse
 ***********************************************************************/
struct Scripture
{
   int bookNumber;
   string book;
   int chapter;
   int verseStart;
   int verseEnd;
};

/***********************************************************************
 * Function: display
 * Description: Displays the passed scripture.
 ***********************************************************************/
void display(const Scripture &scripture, bool hasNumber)
{	
	if (hasNumber)
	{
		if (scripture.verseStart >= scripture.verseEnd &&
			 scripture.verseEnd != 0)
		{
			cout << "Invalid reference.\n";
		}

		else if (scripture.verseStart == 0)
  	 	{
   		cout << scripture.bookNumber << " "
   		     << scripture.book << " "
      		  << scripture.chapter << endl;
   	}

		else if (scripture.verseEnd == 0)
		{
   		cout << scripture.bookNumber << " "
   			  << scripture.book << " "
      		  << scripture.chapter << ":"
 				  << scripture.verseStart << endl;
	   }

   	else

   		/*cout << endl << "bookNumber in scripture.bookNumber in display: " << scripture.bookNumber << endl;*/

   		cout << scripture.bookNumber << " "
   	 		  << scripture.book << " "
      		  << scripture.chapter << ":"
      	  	  << scripture.verseStart << "-"
        		  << scripture.verseEnd << endl;
	}

	else
	{
		if (scripture.verseStart >= scripture.verseEnd &&
			 scripture.verseEnd != 0)
		{
			cout << "Invalid reference.\n";
		}

		else if (scripture.verseStart == 0)
  	 	{
   		cout << scripture.book << " "
      		  << scripture.chapter << endl;
   	}

		else if (scripture.verseEnd == 0)
		{
   		cout << scripture.book << " "
      		  << scripture.chapter << ":"
 				  << scripture.verseStart << endl;
	   }

   	else

   		cout << scripture.book << " "
      		  << scripture.chapter << ":"
      	  	  << scripture.verseStart << "-"
        		  << scripture.verseEnd << endl;
	}
}

void promptFilename(string &filename)
{
   cout << "Filename: ";
   cin >> filename;
}

bool validateBook(string data)
{
	int bookNumber;

	stringstream ss(data);

	ss >> bookNumber;

	if (ss.fail())

		return false;

	else

		return true;
}

void parseString(string data)
{

	Scripture scripture;

	bool hasNumber = validateBook(data);

	if (hasNumber)
	{
   	stringstream s(data);
   	int bookNumber;
   	string book;
   	int chapter;
   	int verseStart;
   	int verseEnd;

	   s >> bookNumber;
   	s >> book;
   	s >> chapter;
   	s >> verseStart;

   	if (s.fail())
   	{
   		verseStart = 0;
   	}

   	s >> verseEnd;

   	if (s.fail())
   	{
   		verseEnd = 0;
   	}

   	scripture.bookNumber = bookNumber;
   	scripture.book = book;
   	scripture.chapter = chapter;
   	scripture.verseStart = verseStart;
	   scripture.verseEnd = verseEnd;

   	display(scripture, hasNumber);
   }

   else
   {
   	stringstream s(data);
   	string book;
   	int chapter;
   	int verseStart;
   	int verseEnd;

   	s >> book;
   	s >> chapter;
   	s >> verseStart;

   	if (s.fail())
   	{
   		verseStart = 0;
   	}

   	s >> verseEnd;

   	if (s.fail())
   	{
   		verseEnd = 0;
   	}

   	scripture.book = book;
   	scripture.chapter = chapter;
   	scripture.verseStart = verseStart;
	   scripture.verseEnd = verseEnd;

   	display(scripture, hasNumber);
   }
}

void readFile(string filename)
{

	string array[500];

   ifstream fin(filename.c_str());
   if (fin.fail())
   {
      return;
   }

   int count = 0;

   while (!fin.eof())
   {
      getline(fin, array[count]);
   
      count++;
   }

   for (int i = 0; i < count - 1; i++)
   {
   	parseString(array[i]);
   }	

}



/***********************************************************************
 * Function: main
 * Description: The driver for the program.
 ***********************************************************************/
int main()
{

   Scripture reference;
   string filename;
   

   // prompt for the name of a file
   promptFilename(filename);
   
   // and pass it to a readFile function
   readFile(filename);


   return 0;
}
