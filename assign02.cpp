/***********************************************************************
* Program:
*    Assignment 02, Digital Forensics  
*    Brother Comeau, CS165
* Author:
*    Brendon Marques
* Summary: 
*    This program will prompt the user for a log file. Then, it will
*    check the logs against the timestamp provided by the user and
*    will display the valid data.
*
*    Estimated:  0.0 hrs   
*    Actual:     1.0 hrs
*      The most difficult part was to get the readFile function to work.
************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// struct
struct Records
{
   string username[500];
   string filename[500];
   long timestamp[500];
};


/**********************************************************************
 * Simply prompts for a filename
 ***********************************************************************/
string promptFilename()
{
   // prompt for the filename and store into a string
   cout << "Enter the access record file: ";
   string file;
   cin >> file;

   cout << endl;
   return file;
}


/**********************************************************************
 * This function reads the information from a file into an
 * array of structs
 ***********************************************************************/
int readFile(Records &data, string file)
{
   // open stream
   ifstream fin(file.c_str());
   if (fin.fail())
   {
      return 0;
   }

   // count the number of lines read
   int count = 0;

   // read the lines from the file
   string temp;
   while (fin >> temp)
   {

      data.filename[count] = temp;
      fin >> data.username[count];
      fin >> data.timestamp[count];

      count++;

   }

   fin.close();

   // return the number of lines read
   return count + 1;
}

/**********************************************************************
 * This function prompts the user for a start time and an end time
 ***********************************************************************/
void promptTimes(long &startTime, long &endTime)
{
   // prompt start and end times
   cout << "Enter the start time: ";
   cin >> startTime;
   cout << "Enter the end time: ";
   cin >> endTime;
   cout << endl;
}


/**********************************************************************
 * This function displays the final results to the user
 ***********************************************************************/
void display(const long &startTime, long &endTime, Records &data, int &count)
{
   // display basic text
   cout << "The following records match your criteria:\n\n";

   // setw to determine alignment
   cout << setw(15) << "Timestamp"
        << " "
        << setw(19) << "File"
        << " "
        << setw(19) << "User"
        << endl
        << "---------------"
        << " "
        << "-------------------"
        << " "
        << "-------------------\n";
   
   // loop through the arrays and display the valid results
   for (int i = 0; i < count; i++)
   {
      if (data.timestamp[i] >= startTime &&
          data.timestamp[i] <= endTime)
      {
         cout << setw(15) << data.timestamp[i]
              << " "
              << setw(19) << data.filename[i]
              << " "
              << setw(19) << data.username[i]
              << endl;
      }
   }
   
   cout << "End of records\n";
}

/**********************************************************************
 * It is the main driver of the program
 ***********************************************************************/
int main()
{
   // call function to prompt filename
   string file = promptFilename();
   
   // struct variable
   Records data;
   
   // read file and return number of lines read
   int count = readFile(data, file);
   
   // variables
   long startTime;
   long endTime;
   
   // prompt for times
   promptTimes(startTime, endTime);
   
   // display results
   display(startTime, endTime, data, count);
   
   // no errors!
   return 0;
}
