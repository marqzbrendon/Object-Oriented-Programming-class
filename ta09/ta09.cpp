#include <iostream>
using namespace std;

class Employee
{
private:

protected:

   string name;

public:
   ~Employee() { }

   void setName(string n) { name = n; }
   string getName() { return name; } 
   virtual void display()
   {
      cout << "Employee: " << name << endl;
   }

   Employee()
   {
      name = "Undefined";
   }

};



class HourlyEmployee : public Employee
{
private:

   int hourlyWage;

public:
   ~HourlyEmployee() { }

   void setHourlyWage(int wage) { hourlyWage = wage; }
   int getHourlyWage() { return hourlyWage; }
   void display()
   {
      cout << name << " - $" << hourlyWage << "/hour\n";
   }

   HourlyEmployee()
   {
      hourlyWage = 0;
   }
};


class SalaryEmployee : public Employee
{
private:

   int salary;

public:
   ~SalaryEmployee() { }

   void setSalary(int sal) { salary = sal; }
   int getSalary() { return salary; }
   void display()
   {
      cout << name << " - $" << salary << "/year\n";
   }

   SalaryEmployee()
   {
      salary = 0;
   }

};


int main()
{
   Employee* employees[3];
   char type;

   for (int i = 0; i < 3; i++)
   {
      do
      {
         cout << "Type of employee (h/s): ";
         cin >> type;
      }
      while (type != 'h' && type != 's');

      if (type == 'h')
      {
         HourlyEmployee *pEmployee = new HourlyEmployee;

         string name;
         int hourlyWage;

         cin.ignore();
         cout << "Employee name: ";
         getline(cin, name);
         pEmployee->setName(name);

         cout << "Hourly wage: ";
         cin >> hourlyWage;
         pEmployee->setHourlyWage(hourlyWage);

         pEmployee->display();

         employees[i] = pEmployee;
      }

      else if (type == 's')
      {
         SalaryEmployee *pEmployee = new SalaryEmployee;

         string name;
         int salary;

         cin.ignore();
         cout << "Employee name: ";
         getline(cin, name);
         pEmployee->setName(name);

         cout << "Salary: ";
         cin >> salary;
         pEmployee->setSalary(salary);

         pEmployee->display();

         employees[i] = pEmployee;
      }
   }

   for (int i = 0; i < 3; i++)
   {
      delete employees[i];
      employees[i] = NULL;
   }

   return 0;
}