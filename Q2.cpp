/*4. CSE department wants to select Programming Coach for its students.
 Any student of the department can be a coach. He need to have
 high profile at least three ACM regional contest participation and number
  of problem solutions of ACM need to more 300. Students need to apply in the department,
  if anyone’s performance is below the requirement he will discard automatically.
    As a student of CSE,
 write OOP code for the project. All the communications will be held by message.*/

#include<bits/stdc++.h>
using namespace std;

class Person
{
    public:
        string name;
        int day;
        int month;
        int year;
        string dept_name;

        Person() {};
        Person(string n,string dp)
        {
            name=n;
            dept_name=dp;
        }
        Person(string n,string dp,int d,int m,int y)
        {
            name=n;
            day=d;
            month=m;
            year=y;
            dept_name=dp;
    }
};

class Student : public Person
{
    public:
        int studentId,ACM,numberOfSolvedProblem;
        Student() {};
        void setData(string n,string dp,int d,int m,int y,int id,int acm,int solve) ///constructor-2
        {
            name=n;
            dept_name=dp;
            day=d;
            month=m;
            year=y;
            studentId=id;
            ACM=acm;
            numberOfSolvedProblem=solve;

        }
        void View_Student_Info()
        {
            cout<<"Student name: "<<name<<endl;
            cout<<"Department_information: "<<dept_name<<endl;
            cout<<"Students Birthday: "<<day<<"-"<<month<<"-"<<year<<endl;
            cout<<"NUMBER Of ACM Contest PARTICIPATION: "<<ACM<<endl;
            cout<<"NUMBER Of SOLVED PROBLEMS: "<<numberOfSolvedProblem<<endl;
        }
    };

class facaculty : public Person
{
    public:
        Student *s;
        string designation;
        facaculty() {};
        void setData(string d,string n,string dept)
        {
            name=d;
            dept_name=dept;
            designation=n;
        }
        void View_facaculty()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Department_info: "<<dept_name<<endl;
            cout<<"Designation: "<<designation<<endl;
        }
        bool Coach_Selection(Student s1)
        {
           // s=s1;
            if(s1.ACM>=3&&s1.numberOfSolvedProblem>300)
                return true;
            else
                return false;
        }
    };
int main()
{
    Student s[3];
    s[0].setData("Mahfuj","CSE",23,07,1997,1001,2,200);
    s[1].setData("Rakib","CSE",22,10,1996,1002,3,201);
    s[2].setData("Helal","CSE",28,02,1998,1003,5,209);

    facaculty fac[2];
    fac[0].setData("Kamal Hossain Chowdhury","Profacessor","CSE");
    fac[1].setData("Partha Chakrabarty","Lecturer","CSE");

    cout<<"THE DETAILS Of FACULTY MEMBER: "<<endl<<endl;
        for(int i=0; i<2; i++){
            fac[i].View_facaculty();
            cout<<endl;
        }
        cout<<endl<<endl;
        cout<<"THE DETAILS Of STUDENTS: "<<endl<<endl;
        for(int i=0; i<3; i++){
            s[i].View_Student_Info();
            cout<<endl;
        }
    cout<<endl<<endl;

    for(int i=0;i<3;i++)
    {
        if(fac[i].Coach_Selection(s[i]))
        {
            cout<<"The student can be coach.."<<endl;
            cout<<"Student's Details: "<<endl;
            s[i].View_Student_Info();
            cout<<endl<<endl;
        }
        else
        {
            cout<<"The student can not be coach.."<<endl;
            cout<<"Student's Details: "<<endl;
            s[i].View_Student_Info();
            cout<<endl<<endl;
        }
    }
    return 0;
}
