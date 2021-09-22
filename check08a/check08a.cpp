/***********************************************************************
* Program:
*    Checkpoint 08a, Inheritance
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

// TODO: Define your Book class here
class Book
{
private:



public:

   string title;
   string author;
   int publicationYear;

   void promptBookInfo()
   {
      cout << "Title: ";
      getline(cin, title);

      cout << "Author: ";
      getline(cin, author);

      cout << "Publication Year: ";
      cin >> publicationYear;
   }

   void displayBookInfo()
   {
      cout << title
           << " ("
           << publicationYear
           << ") "
           << "by "
           << author
           << endl;
   }

};

// TODO: Define your TextBook class here
class TextBook
{
private:



public:

   Book book;
   string subject;

   void promptSubject()
   {
      cout << "Subject: ";
      getline(cin, subject);
   }

   void displaySubject()
   {
      cout << "Subject: "
           << subject
           << endl;
   }

};

// TODO: Add your PictureBook class here
class PictureBook
{
private:



public:

   Book book;
   string illustrator;

   void promptIllustrator()
   {
      cout << "Illustrator: ";
      getline(cin, illustrator);
   }

   void displayIllustrator()
   {
      cout << "Illustrated by "
           << illustrator
           << endl;
   }

};


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare a Book object here and call its methods
   Book book;

   book.promptBookInfo();
   cout << endl;
   book.displayBookInfo();

   // Declare a TextBook object here and call its methods
   TextBook book2;

   cout << endl;
   cin.ignore();
   book2.book.promptBookInfo();
   cin.ignore();
   book2.promptSubject();
   cout << endl;
   book2.book.displayBookInfo();
   book2.displaySubject();


   // Declare a PictureBook object here and call its methods
   PictureBook book3;

   cout << endl;
   book3.book.promptBookInfo();
   cin.ignore();
   book3.promptIllustrator();
   cout << endl;
   book3.book.displayBookInfo();
   book3.displayIllustrator();


   return 0;
}


