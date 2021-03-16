
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

StudentList::StudentList() // default constructor
{
    size = 0;
    temp = new StudentList*[size];
    // This code is really broken. I tried my best but couldn't figure it out.
    // All the math calculations, menu, and structure is correct but I couldn't get it to export/import.
}

StudentList::~StudentList() // default destructor
{
    /*for (int i = 0; i < size; i++)
    {
        delete temp[i];
    } */
    delete [] temp;
}

int StudentList::finalExam() // virtual functions setup for the child classes
{
    return 0;
}

double StudentList::finalAvg()
{
    return 0;
}

char StudentList::letterGrade()
{
    return 0;
}

const char* StudentList::GetFirst() const // returns corresponding data
{
    return first;
}

const char* StudentList::GetLast() const
{
    return last;
}

const char* StudentList::GetClass() const
{
    return course;
}

void StudentList::SetFirst(char *f) // returns corresponding data
{
    strncpy(first, f, 20);
}

void StudentList::SetLast(char *l)
{
    strncpy(last, l, 20);
}

void StudentList::SetClass(char *c)
{
    strncpy(course, c, 20);
}

bool StudentList::ImportFile(const char* filename) // takes in data, however it takes in garbage data for an unknown reason
{
    ifstream input;
    int x;
    int g1, g2, g3, g4, g5, g6, g7, g8;
    char a[20], b[20], c[20];
    
    input.open(filename);
    
    input >> size;
    input.ignore();
    
    StudentList ** temp = new StudentList * [size]; 
    for (int i = 0; i < size; i++)
    {
        input.getline(a, 20, ',');
        input.ignore();
        
        input.getline(b, 20);
        
        input.getline(c, 20, ' ');
        
       if (strcmp(c, "English") == 0)
       {
           input >> g1;
           input >> g2;
           input >> g3;
           input >> g4;
           
           temp[i] = new English(g1,g2,g3,g4);
           
           temp[i]->SetFirst(b);                                                         
           temp[i]->SetLast(a);
           temp[i]->SetClass(c);
       }
       else if (strcmp(c, "History") == 0)                                          
       {
           input >> g1;
           input >> g2;
           input >> g3;
           
           temp[i] = new History(g1,g2,g3);
           
           temp[i]->SetFirst(b);                                                         
           temp[i]->SetLast(a);
           temp[i]->SetClass(c);
       }
       else if (strcmp(c, "Math") == 0)                                                
       {   
           input >> g1;
           input >> g2;
           input >> g3;
           input >> g4;
           input >> g5;
           input >> g6;
           input >> g7;
           input >> g8;
           
           temp[i] = new Math(g1,g2,g3,g4,g5,g6,g7,g8);
           
           temp[i]->SetFirst(b);                                                         
           temp[i]->SetLast(a);
           temp[i]->SetClass(c);        
       }
       input.ignore();      
    }
    input.close(); 
    
    return true;
}

bool StudentList::CreateReportFile(const char* filename) // Usually seg faults, and outputs a blank file
{
    ofstream output;

    int numA = 0;
    int numB = 0;
    int numC = 0;
    int numD = 0;
    int numF = 0;
    
    output.open(filename);
    
    StudentList ** temp = new StudentList * [size]; 
    
    output << "Student Grade Summary\n";
    output << "---------------------\n\n";
    
    output << "ENGLISH CLASS\n\n";
    
    output << "Student                                   Final Final   Letter\n";
    output << "Name                                      Exam  Avg     Grade\n";
    output << "----------------------------------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        if (strcmp(temp[i]->GetClass(), "English") == 0) // seg fault here
        {
            output << temp[i]->GetFirst() << " ";
            output << temp[i]->GetLast();
            output << "                          " ; // incorrect
            output << temp[i]->finalExam() << "    ";
            output << temp[i]->finalAvg() << "   ";
            output << temp[i]->letterGrade() << " " << endl; 
        }       
    }
    output << "\n\n";
    
    output << "HISTORY CLASS\n\n";
    
    output << "Student                                   Final Final   Letter\n";
    output << "Name                                      Exam  Avg     Grade\n";
    output << "----------------------------------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        if (strcmp(temp[i]->GetClass(), "History") == 0)
        {
            output << temp[i]->GetFirst() << " ";
            output << temp[i]->GetLast();
            output << "                          " ; // incorrect
            output << temp[i]->finalExam() << "    ";
            output << temp[i]->finalAvg() << "   ";
            output << temp[i]->letterGrade() << " " << endl;  
        }       
    }
    output << "\n\n";
    
    output << "MATH CLASS\n\n";
    
    output << "Student                                   Final Final   Letter\n";
    output << "Name                                      Exam  Avg     Grade\n";
    output << "----------------------------------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        if (strcmp(temp[i]->GetClass(), "Math") == 0)
        {
            output << temp[i]->GetFirst() << " ";
            output << temp[i]->GetLast();
            output << "                          " ; // incorrect
            output << temp[i]->finalExam() << "    ";
            output << temp[i]->finalAvg() << "   ";
            output << temp[i]->letterGrade() << " " << endl;  
        }       
    }
    output << "\n\n";
    
    output << "OVERALL GRADE DISTRIBUTION\n\n";
    for (int i = 0; i < size; i++)
    {
        if (temp[i]->letterGrade() == 'A')
        {
            numA++;
        }
        else if (temp[i]->letterGrade() == 'B')
        {
            numB++;
        }
        else if (temp[i]->letterGrade() == 'C')
        {
            numC++;
        }
        else if (temp[i]->letterGrade() == 'D')
        {
            numD++;
        }
        else if (temp[i]->letterGrade() == 'F')
        {
            numF++;
        }
    }        
    
    output << "A:   " << numA;
    output << "\nB:   " << numB;
    output << "\nC:   " << numC;
    output << "\nD:   " << numD;
    output << "\nF:   " << numF << endl;
    output.close();
    
    return true;
}

void StudentList::ShowList() const	// Outputs massive errors for calling functions 
{
    cout << "Last                 First                    Course\n\n" ;
    
    StudentList ** temp = new StudentList * [size]; 
    
    for (int i = 0; i < size; i++)
    {
        cout << temp[i]->GetLast();
        cout << "          ";
        cout << temp[i]->GetFirst();
        cout << "          ";
        cout << temp[i]->GetClass() << "\n" ; 
    }
}

English::English(int g1, int g2, int g3, int g4)
{
    attendance = g1;
    project = g2;
    midterm = g3;
    finalexam = g4;
}

int English::finalExam()
{
    return finalexam;
}

double English::finalAvg()
{
    finalavg = (attendance*.1)+(project*.3)+(midterm*.3)+(finalexam*.3);
    return finalavg;
}

char English::letterGrade() 
{
    double g = finalAvg();
    if (g >= 90.00)
        return 'A';
    else if (g >= 80.00)
        return 'B';
    else if (g >= 70.00)
        return 'C';
    else if (g >= 60.00)
        return 'D';
    else
        return 'F';
}

History::History(int g1, int g2, int g3)
{
    paper = g1;
    midterm = g2;
    finalexam = g3;  
}

int History::finalExam()
{
    return finalexam;
}

double History::finalAvg()
{
    finalavg = (paper*.25)+(midterm*.35)+(finalexam*.4);
    return finalavg;
}

char History::letterGrade()
{
    double g = finalAvg();
    if (g >= 90.00)
        return 'A';
    else if (g >= 80.00)
        return 'B';
    else if (g >= 70.00)
        return 'C';
    else if (g >= 60.00)
        return 'D';
    else
        return 'F';
}

Math::Math(int g1, int g2, int g3, int g4, int g5, int g6, int g7, int g8)
{
    quiz1 = g1;
    quiz2 = g2;
    quiz3 = g3;
    quiz4 = g4;
    quiz5 = g5;
    test1 = g6;
    test2 = g7;
    finalexam = g8;
}

int Math::finalExam()
{
    return finalexam;
}

double Math::finalAvg()
{
    quizavg = (quiz1+quiz2+quiz3+quiz4+quiz5) / 5.0;
    finalavg = (quizavg*.15)+(test1*.25)+(test2*.25)+(finalexam*.35);
    return finalavg;
}

char Math::letterGrade()
{
    double g = finalAvg();
    if (g >= 90.00)
        return 'A';
    else if (g >= 80.00)
        return 'B';
    else if (g >= 70.00)
        return 'C';
    else if (g >= 60.00)
        return 'D';
    else
        return 'F';
}
