
/* Name: Andrew Stade
Date: 4/10/2020
Section: 2 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <cstring>
#include <string>
#include "studentlist.h"

using namespace std;

void MainMenu()
{
    cout << "\n\t " << "\t*** Student List menu *** \n" ;
    cout << "\tI" << "\tImport students from a file\n" ;
    cout << "\tS" << "\tShow student list (brief)\n" ;  
    cout << "\tE" << "\tExport a grade report (to file)\n" ;
    cout << "\tO" << "\tsOrt student list\n" ;
    cout << "\tM" << "\tShow this Menu\n" ;
    cout << "\tQ" << "\tQuit Program" ;    
}

int main()
{
    StudentList s;
    ifstream in1;
    ofstream out1;
    char infile[30];
    char outfile[30];
    char choice;
    
    cout << "\n";
    MainMenu();
    
    do
    {
        cout << "\n> ";
        cin >> choice;
        
        if (choice == 'I' || choice == 'i') // Import file option
        {
            in1.clear(); // Clears the input, allows for multiple program trials
	
            cout << "Enter filename: " ;
            cin >> infile; // Asks for a file to be input
		
            if (!in1) // Error checking
            {
                cout << "Invalid file. No data imported" << endl;
            }
            s.ImportFile(infile);
        }
        else if (choice == 'S' || choice == 's') // Show student list (brief)
        {
            s.ShowList();
        }
        else if (choice == 'E' || choice == 'e') // Export file option
        {
            out1.clear();
            
            cout << "Enter filename: " ;
            cin >> outfile; // Asks for a file to be output
            
            s.CreateReportFile(outfile);
        }
        else if (choice == 'O' || choice == 'o') // Extra Credit: Sort option
        {
            
        }
        else if (choice == 'M' || choice == 'm')
        {
            MainMenu();
        }
        else if (choice != 'Q' && choice != 'q')
        {
            cout << "Invalid menu choice. Try again."; 
        }
    } while (choice != 'Q' && choice != 'q');
    
    cout << "\nGoodbye!" << endl;

    
    
    return 0;
}