/*Create a 'DISTANCE' class with :
- feet and inches as data members
- member function to input distance
- member function to output distance
- member function to add two distance objects
Write a main function to create objects of DISTANCE class. Input two distances
and
output the sum
*/

#include <iostream>
using namespace std;

class Distance 
{
	public :
	int feet , inches ;
	void getinfo()
	{
		cout << "Enter the feet and inches :";
		cin >> feet >> inches ;
	}
	void display()
	{
		cout << "Feet:" << feet << "\tInches:" << inches ;
	}
	void add(Distance , Distance );
};

 void Distance::add(Distance d1 , Distance d2 )
	{
		int t;
		t= d1.inches + d2.inches ;
		int carry = t/12 ;
		feet = d1.feet + d2.feet + carry ;
	    inches = t % 12 ;
	}

int main() {
   Distance d1 , d2 ,d3 ;
   d1.getinfo();
   d2.getinfo();
   d3.add(d1,d2 );
   cout<< "After adding the sum is \n";
   d3.display();
   
  return 0;
}
