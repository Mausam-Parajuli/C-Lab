// a. Define an instance object of class DateTime called Watch.
// b. Write a main () function that would initialize the values through the constructor
// functions, and then allows them to be reset through the set () functions. Be sure and
// display the results following the constructor before you use the set functions.
// c. Through the use of the display () function, the time and date are to be displayed. Note
// that the display () functions in all three classes need to be defined, as well as the
// constructor and all the access functions.

/*

*/

#include <iostream>

using namespace std;

class Date {
    int day, month, year;

    public:
        Date(int d, int m, int y) : day(d), month(m), year(y){}
        ~Date(){};
        void display(){
        	cout<<"\n Date:\n";
            cout << year << "/" << month << "/" << day << endl;
        }; // displays the date
        Date get(){
            return *this;
        };     // accesses the date members
        void set(int d, int m, int y){
            day = d;
            month = m;
            year = y;
        }     // sets the date members
};

class Time {
    int hour;
    int minute;
    int second;

    public:
        Time(int h, int m, int s) : hour(h), minute(m), second(s){}
        ~Time(){};
        void display(){
        	cout<<"\n Time :\n";
            cout << hour << ":" << minute << ":" << second << endl;
        } 
        Time get(){
            return *this;
        };     // accesses the time members
        void set(int h, int m, int s){
            hour = h;
            minute = m;
            second = s;
        };     // sets the time members
};

class DateAndTime : public Date, public Time {
    public:
        DateAndTime(int d, int m, int y, int h, int min, int s) : Date(d, m, y) , Time(h, min, s){}

        void display(){
            Date :: display();
            Time :: display();
        }; // prints date and time
};

int main(){
    DateAndTime Watch(11, 11, 2024, 10, 10, 45);
    cout << "Initially :" << endl;
    Watch.display();
    Watch.Date::set(21, 5, 2024);
    Watch.Time::set(2,30,42);
    cout << "\nAfter Reset :" << endl;
    Watch.display();
}
