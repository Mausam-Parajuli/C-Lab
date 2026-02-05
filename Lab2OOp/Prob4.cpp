/*
Create a class called 'TIME' that has
- three integer data members for hours, minutes and seconds
- constructor to initialize the object to zero
- constructor to initialize the object to some constant value
- overload +,- to add and subtract two TIME objects
- overload > function to compare two time
- member function to display time in HH:MM:SS format
*/

#include<iostream>
using namespace std;

class Time{
    int hour;
    int min;
    int sec;

    public:
        Time(){
            hour=0;
            min = 0;
            sec = 0;
        }
        Time(int h, int m, int s){
            hour = h;
            min = m;
            sec = s;
        }

        void output(){
            cout << hour << ":" << min << ":" << sec << endl;
        }

        Time operator+(Time &obj){
            Time t;
            t.hour = hour + obj.hour;
            t.min = min + obj.min;
            t.sec = sec + obj.sec;

            t.min += t.sec/60;
            t.sec %= 60;
            t.hour += t.min/60;
            t.min%=60;
            return t;
        }

        Time operator-(Time &obj){
            Time t;
      		if(hour>obj.hour){
            t.sec = hour * 3600 + min * 60 + sec - (obj.hour * 3600 + obj.min * 60 + obj.sec);
            t.min = t.sec/60;
            t.sec %= 60;
            t.hour = t.min / 60;
            t.min %= 60;
            return t;
            }
            else {
            	t.sec = (obj.hour * 3600 + obj.min * 60 + obj.sec) -( hour * 3600 + min * 60 + sec );
            	t.min = t.sec/60;
				t.sec = t.sec%60;
				t.hour = t.min/60;
		 		t.min = t.min%60;
				return t;
				}
        }

       int operator>(Time &obj){
            if (hour > obj.hour)
               cout<<hour<<":"<<min<<":"<<sec<<" > "<<obj.hour<<":"<<obj.min<<":"<<obj.sec; 
        	else cout<<obj.hour<<":"<<obj.min<<":"<<obj.sec<<" > "<<hour<<":"<<min<<":"<<sec; 
           
		   return 0;   
        } 
};

int main(){
    Time t1 , t2 , ts ,tm;
    int h , m , s;
    cout<<"Enter the hour , min and sec :" ;
    cin>>h>>m>>s;
    t1= Time(h,m,s);
    cout<<"Enter the hour , min and sec :";
    cin>>h>>m>>s;
    t2 = Time(h,m,s);
    ts = t1 + t2;
    tm = t1 - t2;
    cout<<"Sum :";
    ts.output();
    cout<<"Difference :";
    tm.output();
    cout<<"Compare :";
    cout << (t1 > t2);
    
    return 0;
}
