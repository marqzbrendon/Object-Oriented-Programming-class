#include <iostream>
#include <vector>
using namespace std; 

void promptNumbers(vector<int> &n)
{
   int num = 1;

   while (num != 0)
   {
      cout << "Enter a number: ";
      cin >> num;

      n.push_back(num);
   }

   cout << endl;
}

void displayNumbers(vector<int> &n)
{

   

   for (vector<int>::iterator it = n.begin(); it != n.end(); ++it)
   {
      if (*it != 0)
     {
         cout << *it << endl;
     }
   }

   cout << endl;
}

void removeOdds(vector<int> &n)
{
   for(vector<int>::iterator it = n.begin(); it != n.end(); )
   {
      if (*it % 2 != 0)
      {
         it = n.erase(it);
      }

      else
      {
         ++it;
      }
   }

}

int main()
{
   vector<int> numbers;

   promptNumbers(numbers);
   displayNumbers(numbers);
   removeOdds(numbers);
   displayNumbers(numbers);

   return 0;
}