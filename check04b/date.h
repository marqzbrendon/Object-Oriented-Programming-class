/********************************************************************
 * File: date.h
 * Purpose: Holds the definition of the Date class.
 ********************************************************************/

#ifndef DATE_H
#define DATE_H
using namespace std;

// put your class definition here
// along with the data members, and method prototypes
class Date
{
private:

	int month;
	int day;
	int year;

public:

	void set(int &dayN, int &monthN, int &yearN);
	void displayAmerican();
	void displayEuropean();
	void displayISO();

};




#endif
