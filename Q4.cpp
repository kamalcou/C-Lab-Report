/*2. Like Uber, CNG owners want to develop a software which can communicate with customer
and driver. A customer needs to say his/her destination and nearer CNG driver will
get message from the Uber company with name and mobile number of the customer.
The driver can make a direct call and if the customer confirms the ride then driver will
come to spot and carry the passenger. As a student of CSE, write OOP code for the project.
You need to pass message from one end to another end to make communications.*/
#include<bits/stdc++.h>

#define PI 3.1416

using namespace std;

class Person
{
protected:
    string name;
    int national_id;

public:
    Person(){};

    Person(string name, int national_id)
    {
        this->name = name;
        this->national_id = national_id;
    }
};

class Driver : public Person
{
    int mobile_number;
    string current_location;

public:
    double latitude;
    double longitude;

    Driver(){};

    Driver(string name, int national_id, int mobile_number, string current_location, double latitude, double longitude) : Person(name, national_id)
    {
        this->mobile_number = mobile_number;
        this->current_location = current_location;
        this->latitude = latitude;
        this->longitude = longitude;
    }

    void driverfile()
    {
        ofstream myfile2;
            myfile2.open("Driver Information.txt");

        myfile2 << "Driver Details" << endl;
        myfile2 << "-------------------------------" << endl;
        myfile2 << "Driver Name : " << name << endl;
        myfile2 << "National ID : " << national_id << endl;
        myfile2 << "Mobile Number : " << mobile_number << endl;
        myfile2 << "Current Location : " << current_location << endl;
        myfile2 << "Latitude : " << latitude << " degree" << endl;
        myfile2 << "Longitude : " << longitude << " degree" << endl;
        myfile2 << "-------------------------------" << endl;

        myfile2.close();
    }

    void booking()
    {
        cout << "a seat has been confirmed." << endl;
    }
};

class Uber
{
    Driver driver1, driver2;

public:
    void driver_list(Driver driver1, Driver driver2)
    {
       this->driver1 = driver1;
       this->driver2 = driver2;
    }

    double calculate_distance(double customer_latitude, double customer_longitude, double driver_latitude, double driver_longitude)
    {
        int Radius = 6371;

        double DLat = (driver_latitude - customer_latitude) * (PI / 180);
        double DLon = (driver_longitude - customer_longitude) * (PI / 180);

        double A = pow(sin(DLat/2),2) + cos(customer_latitude) * cos(driver_latitude) * pow(sin(DLon/2),2);

        double C = 2 * atan2(sqrt(A) , sqrt(1-A));
        double distance = Radius * C;

        return distance;
    }

    void contact_with_driver(double customer_latitude, double customer_longitude)
    {
        double distancefromdriver1, distancefromdriver2;

        distancefromdriver1 = calculate_distance(customer_latitude, customer_longitude, driver1.latitude, driver1.longitude);
        distancefromdriver2 = calculate_distance(customer_latitude, customer_longitude, driver2.latitude, driver2.longitude);

        if(distancefromdriver1 < distancefromdriver2)
            driver1.booking();

        else
            driver2.booking();
    }
};

class Customer : public Person
{
    int mobile_number;
    string destination;
    double latitude;
    double longitude;

public:
    Customer(){};

    Customer(string name, int national_id, int mobile_number, string destination, double latitude, double longitude) : Person(name, national_id)
    {
        this->mobile_number = mobile_number;
        this->destination = destination;
        this->latitude = latitude;
        this->longitude = longitude;
    }

    void customerfile()
    {
        ofstream myfile1;
            myfile1.open("Customer Information.txt");

        myfile1 << "Customer Details" << endl;
        myfile1 << "----------------------------" << endl;
        myfile1 << "Customer Name : " << name << endl;
        myfile1 << "National ID : " << national_id << endl;
        myfile1 << "Mobile Number : " << mobile_number << endl;
        myfile1 << "Destination : " << destination << endl;
        myfile1 << "Latitude : " << latitude << " degree" << endl;
        myfile1 << "Longitude : " << longitude << " degree" << endl;
        myfile1 << "----------------------------" << endl;

        myfile1.close();
    }

    void contact_with_uber(Uber uber)
    {
        double latitude, longitude;

        this->latitude = latitude;
        this->longitude = longitude;

        cout << "For customer " << this->name << ", whose Destination is " << this->destination << ", ";

        uber.contact_with_driver(latitude, longitude);
    }
};

int main()
{
    Customer customer("Rakibul", 1998000001, 20971521, "Dhaka", 23, 91);

    customer.customerfile();

    Driver driver1("Rahim", 1990000001, 23068695, "Comilla", 23, 91);
    Driver driver2("Karim", 1991000010, 23068680, "Narayanganj", 22, 92);

    driver1.driverfile();
    driver2.driverfile();

    Uber uber;
    uber.driver_list(driver1, driver2);

    customer.contact_with_uber(uber);

    return 0;
}
