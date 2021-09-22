/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H

class Money
{
private:
   int dollars;
   int cents;

public:
   void prompt();
   void display() const;
   int getDollars() const;
   int getCents() const;
   void setDollars(int dol);
   void setCents(int cen);

   Money()
   {
      dollars = 0;
      cents = 0;
   }

   Money(int dollars)
   {
      if (dollars < 0)
      {
         dollars = dollars * -1;
      }

      this->dollars = dollars;
      cents = 0;
   }

   Money(int dollars, int cents)
   {
      if (dollars < 0)
      {
         dollars = dollars * -1;
      }

      if (cents < 0)
      {
         cents = cents * -1;
      }

      this->dollars = dollars;
      this->cents = cents;
   }
};

#endif
