/***************************************************************
 * File: rational.h
 * Author: Brendon Marques
 * Purpose: Contains the definition of the Rational class
 ***************************************************************/
#ifndef RATIONAL_H
#define RATIONAL_H

// put your class definition here
class Rational
{
private:
	int top;
	int bottom;

	int multTop;
	int multBot;

public: 
	void prompt();
	void display();
	void displayDecimal();
	void multiplyBy(int &multTop, int &multBot);
	void reduce();
};

#endif
