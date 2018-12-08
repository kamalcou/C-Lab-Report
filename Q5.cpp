/*5. A Mess owner wants to develop a software for its mess members.
Everyday mess member meal details will be entered in the software and after the month
it will show the bill of the mess member. Mess member deposit at least 1000 tk at
beginning of the month. As a student of CSE, write OOP code for the project.
All the communications will be held by message.*/
#include<bits/stdc++.h>
using namespace std;
class Person
{
public:
    Person() {}
    string name;
    string date;
};

class Manager
{
public:
    class Member : public Person
    {
    public:
        void fetch_name(string names, string date_of_birth)
        {
            name = names;
            date = date_of_birth;

        }

        class Meal
        {
        public:
            static int counter1,counter2;
            float deposit, total_cost, meal_rate;
            int t_meal;
            string cmeal[15],  date[31];

            get_meal(int total_meal, float deposits, float meal_rate)
            {
                total_cost = total_meal * meal_rate;
                deposit = deposits;
                t_meal = total_meal;
                this->meal_rate=meal_rate;
            }

            meal_count(string dates,string meals,int Members)
            {
                date[counter1] = dates;
                cmeal[counter1] = meals;
                if(counter2 % Members == Members - 1)
                    counter1++;
                counter2++;

            }
        };


        view(int counter,int DayCount)                           /// function for viewing Meal information
        {
            cout << "Member No :"<< counter << endl;
            cout << "Name : " << name <<endl;
            cout << "Date of Birth : " << date <<endl;
            cout << "---------------------------" <<endl;
            cout<< "Total Deposit --> " << ml.deposit << endl;
            cout << "Total meal    --> " << ml.t_meal << endl;
            cout << "Meal Rate     --> " << ml.meal_rate << endl;
            cout << "Total Cost    --> " << ml.total_cost <<  endl;
            cout << "Total Balance --> " << ml.deposit - ml.total_cost << endl<<endl;
            cout << "----Meal Information of " << name << "----\n"<<endl;
            for(int j = 1; j<DayCount; j++)
                cout << ml.date[j] << " --> " << ml.cmeal[j] <<endl;
            cout << endl<<endl;
            cout << "---------------------------" <<endl;
            cout << "---------------------------" <<endl<<endl<<endl;
        } Meal ml ;
    };
    Member members[15];
};

view_print(int deposite,int shopping,int TotalMeal,float meal_rate,int Members)
{
    cout << endl << "Meal Informations : " << endl;
    cout << "--------------------------------------" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Total Member : " << Members << endl;
    cout << "Total Deposites : "  << deposite << endl;
    cout << "Total Cost : "  << shopping << endl;
    cout << "Total Meal : "  << TotalMeal << endl;
    cout << "Meal Rate : "  << meal_rate << endl;
    cout << "--------------------------------------" << endl;
    cout << "--------------------------------------" << endl << endl;
}
int Manager::Member::Meal :: counter1;              ///Defination of Static Data Member
int Manager::Member::Meal:: counter2;              ///Defination of Static Data Member
int main()
{
    Manager manager;
    string name,date_of_birth,deposite,date,cmeal[31][15];
    int counter=0,TotalMeal = 0;
    int DayCount = 0;
    string apps;

    string MeaL[31];
    ifstream file,file_2;

    /***---------------Open csv file for Total Member Counting--------------------***/

    file.open("F:\Kamal Sir_ C++\Lab report\Students.csv");
    int MemberCount = 0;

    while(file.good())
    {
        getline(file,name,',');
        getline(file,date_of_birth, ',');
        getline(file,deposite, '\n');
        MemberCount++;

    }
    MemberCount = MemberCount - 1;

    file.close();

    /***---------------Open csv file for Total Day Counting--------------------***/


    file_2.open("F:\Kamal Sir_ C++\Lab report\Students.csv");       ///Open a csv file named meal

    while(file_2.good())                        ///days count (end of the file)
    {
        getline(file_2,date,',');

        for(int mem=0; mem<MemberCount; mem++)
        {
            if(mem==MemberCount - 1)
                getline(file_2, cmeal[mem][counter], '\n'); ///for last Person
            else
                getline(file_2, cmeal[mem][counter], ',');
        }     ///others
        DayCount++;
    }
    DayCount = DayCount - 1;

    file_2.close();


    int total[DayCount]= {0};

    /***---------------Open csv file for Total Meal Counting--------------------***/

    file_2.open("F:\Kamal Sir_ C++\Lab report\Students.csv");       ///Open a csv file named meal

    /// while(file_2.good())                        ///days count (end of the file)
    for(int i = 0; i<DayCount; i++)
    {
        getline(file_2,date,',');

        for(int mem=0; mem<MemberCount; mem++)
        {
            if(mem==MemberCount - 1)
                getline(file_2, cmeal[mem][counter], '\n'); ///for Person 6
            else
                getline(file_2, cmeal[mem][counter], ',');         ///others

            for(int i=0; i<DayCount; i++)
                if(counter == i)
                    MeaL[i] = cmeal[mem][counter];

            int DayTMeal[DayCount];
            int num[DayCount];
            memset(DayTMeal, 0, sizeof(DayTMeal));
            memset(num, 0, sizeof(num));
            for(int i = 0; i<DayCount; i++)
            {
                if(counter != i)
                    continue;
                if(counter == i)
                {
                    for(int j=0; MeaL[i][j]; j++)
                    {
                        if(MeaL[i][j]>='0' and MeaL[i][j]<='9')
                        {
                            num[i] *= 10;
                            num[i] += (MeaL[i][j]-'0');
                        }
                        else
                        {
                            DayTMeal[i] += num[i];
                            num[i] = 0;
                        }
                    }
                    DayTMeal[i] += num[i];
                }
                else
                    DayTMeal[i] = 0;
            }

            for(int i=0; i<MemberCount; i++)
            {
                if(mem == i )
                {
                    for(int j=0; j<DayCount; j++)          /// individual meal count
                        total[i] += DayTMeal[j];
                }
            }

            manager.members[mem].ml.meal_count(date,cmeal[mem][counter],MemberCount);
        }
        counter++;
    }

    file_2.close();              ///file closed (meal)

    ifstream bz;
    string baz;
    int shopping =0,m;
    bz.open("F:\Kamal Sir_ C++\Lab report\Blacklist.csv");                                        ///Open a csv file named bazar

    while(bz.good())
    {
        getline(bz, baz,'\n');
        stringstream gerk(baz);
        gerk >> m;
        shopping += m;
    }
    shopping = shopping - m;

    for(int i=0; i<MemberCount; i++)
        TotalMeal += total[i];

    bz.close();
    float meal_rate = shopping / (float)TotalMeal;


    file.open("F:\Kamal Sir_ C++\Lab report\Students.csv");
    ///Open a csv file named "name"

    int deposites = 0,n;
    string Name[MemberCount];
    for(int i = 0; i<MemberCount; i++)
    {
        float final_dep = 0.0;
        getline(file,name,',');
        getline(file,date_of_birth, ',');
        getline(file,deposite, '\n');

        stringstream geek(deposite);                                    ///converts strings into integer
        geek >> final_dep;
        deposites += final_dep;
        Name[i] = name;
        manager.members[i].fetch_name(name,date_of_birth);
        manager.members[i].ml.get_meal(total[i],final_dep,meal_rate);

    }
    file.close();                             ///file closed (name)
//cout << name << endl;
    string password = "**********";
    string getpassword;

//cin >> getpassword;
    while(true)
    {
        cout << "Please enter your Password : " ;
        cin >> getpassword;
        if(password == getpassword)
        {
            view_print(deposites,shopping,TotalMeal,meal_rate,MemberCount); ///overall meal info
            break;
        }
        else
            cout << endl << "Your password is incorrect,please try again." << endl << endl;
    }
    string NameUpper[MemberCount],NameLower[MemberCount];



    while(true)
    {

        string Person;
        cout << "Enter Member Name : " << endl;
        cin >> Person;
        for(int i = 0; i<Person.size(); i++)
        {
            if(i == 0)
                Person[i]=toupper(Person[i]);
            else
                Person[i]=tolower(Person[i]);
        }
        int y;
        //                 ///individual meal info show
        for(int i = 0; i<MemberCount; i++)
        {
            if(Person == Name[i])
            {
                y = i;
                cout << endl << "Mess Members Information :" << endl << endl;
                manager.members[y].view(y+1,DayCount);
                break;
            }
        }

    }
    return 0;
}
