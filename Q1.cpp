/**Q1:Write C++ code in object oriented approach for the students.Student can be rewarded from the department
if he gets good GPA in a semester and solved at least 100 ACM problems in the last year.Department will publish
the top 5 students name in their honor board. As a student of CSE, write OOP code for the project.**/

#include<bits/stdc++.h>
using namespace std;
class Person{
    public:
    string name;
    int age;

};
class Student: public Person
{
    private:
        //string Name;
        //int Age;
        float GPA;
        int ACM_Solve;

    public:
        Student(){};
        void setData(string n, int a, float g, int s)
        {
            Name=n;
            Age=a;
            GPA=g;
            ACM_Solve=s;
        }
        int checkGPA(float gpa)
        {
            if(GPA==gpa && ACM_Solve>=100)
                return 1;
            else return 0;
        }
        float getGPA()
        {
            return GPA;
        }
        void showStudentDetails()
        {
            cout << setw(10) << Name << setw(13) <<  GPA << setw(13) << ACM_Solve << endl << endl;
        }
};

int main()
{
    Student performance[10];

    performance[0].setData("Rakib",19,2.98,50);
    performance[1].setData("Sourob",21,3.08,100);
    performance[2].setData("Helal",20,3.25,200);
    performance[3].setData("Osman",20,3.23,100);
    performance[4].setData("Ariyan",19,3.07,110);
    performance[5].setData("Tonnoy",21,3.08,150);
    performance[6].setData("Utso",20,3.45,200);
    performance[7].setData("Sabbir",21,3.07,78);

    cout << "TOP 5 students on the Honor Board are:" << endl << endl;
    cout << setw(10) << "Student Name"  << setw(10) << "GPA" << setw(17) << "ACM Solve" << endl  ;
    cout << setw(10) << "____________"  << setw(10) << "___" << setw(17) << "_________" << endl << endl ;

    int counter=0;
    int maxCheck[10]={0};
    float maxGPA=0;
    int key=0;
    for(int i=0;i<=7;i++)
    {

        maxGPA=0;
        for(int j=0;j<=7;j++)
        {
            if(maxGPA<performance[j].getGPA() && maxCheck[j]==0)
            {
                maxGPA=performance[j].getGPA();
                key=j;
            }
        }
        maxCheck[key]=1;
        if(performance[key].checkGPA(maxGPA)==1)
        {
            counter++;
            performance[key].showStudentDetails();
        }
        if(counter==5) break;

    }

    return 0;
}
