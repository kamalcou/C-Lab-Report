/*3. CSE department wants to manage a Fast-food shop in its premise.
Every student can make pre-order of his/her breakfast before 10 PM of the previous day.
A sales person can manage the data and sells the preordered item to the students.
If a student pre-ordered before but not take his/her breakfast and the sales person can
inform it to the department. If he will not be illegible to pre-order the breakfast another
 time. As a student of CSE,
write OOP code for the project. All the communications will be held by message.*/
#include<bits/stdc++.h>
using namespace std;
class Date
{
public:
    string date;
    Date() {};
    Date(string date)
    {
        this->date=date;
    }
};
class Person
{
public:
    string name;
    Person()
    {
        ;
    }
    Person(string a)
    {
        name = a;
    }

};

class Department
{
public:
    string dpt_name;
    Department() {};
    Department(string name)
    {
        dpt_name=name;
    }
};

class Student : public Person,Date
{
public:
    int age;
    int id;
    Student()
    {
        ;
    }
    Student(string a,string b,int c,int d) : Person(a),Date(b)
    {
        age = c;
        id = d;
    }
    void view()
    {
        cout<<"Name: "<<name<<" Age: "<<age<<" ID: "<<id<<" Birthday: "<<date<<endl;
    }
    friend orderfood();
    friend blacklist();
};
class Sellsman : public Person,Date
{
public:
    int seller_no;
    Sellsman() {};
    Sellsman(string name,string date2,int seller_no): Person(name),Date(date2)
    {
        this->seller_no=seller_no;
    };
    view_sellsman()
    {
        cout<<"Sells person Name: "<<name<<endl;
        cout<<"Birthday: "<<date<<endl;
    }
    friend orderfood();

};
class Faculty : public Person
{
public:
    string designation;
    Department department;
    Faculty() {};
    Faculty(string designation,string name,Department department1):Person(name)
    {
        this->designation=designation;
        department=department1;
    }
    view_faculty()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Department: "<<department.dpt_name<<endl;
        cout<<"Designation: "<<designation<<endl;
    }
    Blacklist(int order_data[],string deliver_data[],Student *student[],string blacklist[])
    {
        cout<<"Blacklisted names are: \n";
        for(int n=0; n<4; n++)
        {
            if(order_data[n]==1)
                if(deliver_data[n]=="Didn't")
                {
                    blacklist[n]=student[n]->name;
                    cout<<"Name: "<<student[n]->name<<"\nID: "<<student[n]->id<<"\nYou have been blacklisted, Contact with Department"<<endl;
                }
        }
    };
};
int view_time()
{
    time_t k = time(0);
    struct tm *t = localtime(&k);
    cout<< t->tm_hour << ":" << t->tm_min << endl;
    return t->tm_hour;
}

int orderfood(Student *student)
{
    int tm=view_time();
    if(tm>22)
    {
        cout<<"Sorry, You cannot Place the pre-order.\n";
        return -1;
    }
    else
    {
        cout<<"Name: "<<student->name<<"\nID: "<<student->id<<"\n Your Order Has been placed.\n";
        return 1;
    }
}
int main()
{
    Student *students[5]=
    {
        new Student("Rajib","12-12-1996",20,11708008),
        new Student("Sourob","13-10-1995",21,11708007),
        new Student("Samir","01-09-1995",19,11708005),
        new Student("Sadik","10-01-1995",20,11708019),
        new Student("Raihan","10-10-1996",19,11708020),
    };
    cout<<"Student Details: "<<endl;
    for(int i=0; i<4; i++)
    {
        students[i]->view();
    }
    Sellsman sells_person("Asikh","13-04-1990",1);
    cout<<"Sells Person Detail: "<<endl;
    sells_person.view_sellsman();
    Department department("CSE");
    Faculty *faculty_member[2]=
    {
        new Faculty("Professor","Kamal Hossain",department),
        new Faculty("Lecturer","Mahmudul Hasan Raju",department)
    };
    cout<<"Teacher's Details: "<<endl;
    for(int i=0; i<2; i++)
    {
        faculty_member[i]->view_faculty();
    }
    int order_data[5],g=0;
    for(int i=0; i<5; i++)
    {

        g=orderfood(students[i]);
        order_data[i]=g;

    }
    string delivery_info[5]= {"ordered","Didn't","ordered","Didn't"};
    string blacklisted_members[5];
    faculty_member[0]->Blacklist(order_data,delivery_info,students,blacklisted_members);

    ofstream students_file;
    students_file.open("Students.csv");
    students_file<<"Students are: \n";
    students_file<<"Roll,Name,Department\n";
    for(int i=0; i<5; i++)
    {
        students_file<<students[i]->id<<","<<students[i]->name<<","<<endl;
    }



    ofstream blacklist_file;                    ///Blacklist part
    blacklist_file.open("Blacklist.csv");

    int counter=1;
    blacklist_file<<"Blacklisted names are:\n";
    blacklist_file<<"Roll,Name,Department\n";
    string blacklisted_id[5];
    for(int i=0; i<5; i++)
    {
        if(blacklisted_members[i]!="\0")
        {
            blacklist_file<<students[i]->id<<","<<blacklisted_members[i]<<","<<endl;
            counter++;
            blacklisted_id[i]=students[i]->id;

        }
    }
    blacklist_file.close();
    cout<<"Blacklisted person included in file.\n";
    cout<<"New to order service?\nPress 1 to register or 0 to exit"<<endl;
    int new_order;
    cin>>new_order;
    while(new_order!=0)
    {
        string name,department_name,birthday,roll;
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"\nEnter ID:";
        cin>>roll;
        cout<<"\nEnter Department: ";
        cin>>department_name;
        cout<<"\nEnter birthday:";
        cin>>birthday;
        string age;
        int id, date;
        students[5]= {new Student(name,age,id,date)};
        //5+=1;
        int order_data1;
        order_data1=orderfood(students[5-1]);
        cin>>new_order;
        if(new_order!=1)
            break;
    }
    string delivery_data2[5]= {"ordered","Didn't","ordered","Didn't","ordered"};
    int temp;
    for(int i=temp; i<5; i++)
    {
        students_file<<students[i]->id<<","<<endl;
    }
    return 0;
}
