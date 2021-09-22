/*******************
 * NumberList class
 *******************/
#ifndef NUMBER_LIST_H
#define NUMBER_LIST_H

#include <iostream>

class NumberList
{
private:
   int size;
   int *array;

public:
   NumberList()
   {
      size = 0;
      array = NULL;
   }


   // TODO: Add your constructor and destructor
   NumberList(int size);

   NumberList(const NumberList &rhs);

   NumberList & operator = (const NumberList &rhs);


   ~NumberList()
   {  
      delete array;
      array = NULL;
      std::cout << "Freeing memory\n";
   }



   int getNumber(int index) const;
   void setNumber(int index, int value);
   
   void displayList() const;

};

#endif
