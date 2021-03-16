
/* Name: Andrew Stade
Date: 4/10/2020
Section: 2 */


class StudentList
{
public:
   StudentList();		// starts out empty
   ~StudentList();		// cleanup (destructor)
   
   const char* GetFirst() const;
   const char* GetLast() const;
   const char* GetClass() const;
   void SetFirst(char *f);
   void SetLast(char *l);
   void SetClass(char *c);
   
   virtual int finalExam();
   virtual double finalAvg();
   virtual char letterGrade();

   bool ImportFile(const char* filename);
   bool CreateReportFile(const char* filename);
   void ShowList() const;	// print basic list data

protected:
    StudentList** temp;
    int size;
    char first[20];
    char last[20];
    char course[20];
};

class English : public StudentList
{
public:
    English(int a1, int p2, int m3, int f4);
    
    int finalExam();
    double finalAvg();
    char letterGrade();

private:   
    int attendance;
    int project;
    int midterm;
    int finalexam;
    double finalavg;
};

class History : public StudentList
{
public:
    History(int p1, int m2, int f3);
    
    int finalExam();
    double finalAvg();
    char letterGrade();
    
private:   
    int paper;
    int midterm;
    int finalexam;
    double finalavg;
};

class Math : public StudentList
{
public:
    Math(int q1, int q2, int q3, int q4, int q5, int t6, int t7, int f8);
    
    int finalExam();
    double finalAvg();
    char letterGrade();

private:   
    int quiz1;
    int quiz2;
    int quiz3;
    int quiz4;
    int quiz5;
    int test1;
    int test2;
    int finalexam;
    double quizavg;
    double finalavg;
};