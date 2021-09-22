/*****************************************************
 * File: pair.h
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H

// TODO: Fill in this class
// Put all of your method bodies right in this file
template <class T, class U>
class Pair
{
   public:

      Pair()
      {
         data1;
         data2;
      }

      Pair(T a, U b)
      {
         data1 = a;
         data2 = b;
      }

      T getFirst() { return data1; }
      void setFirst(T value1) { data1 = value1; }

      U getSecond() { return data2; }
      void setSecond(U value2) { data2 = value2; }

      void display() { std::cout << data1 << " - " << data2; }

   private:

      T data1;
      U data2;
};


#endif // PAIR_H
