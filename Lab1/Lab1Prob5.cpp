/*
 Problem 5:
To write a program to categorize employees based on designation using
static data members.
Algorithm:
1. Start
2. Create a class for employee with two count variables declaring as a static
member and employee id, name and designation as other data members.
3. Get the employee id name and designation from the user.
4. If the designation is MANAGER increment first count by 1 and if it is
ENGINEER increment second count by 1.
5. Finally display the total number of managers, engineers and employees.
6. Stop.
To write a C++ program to add two private data members using friend functions.
*/
#include<iostream>
#include<string>
using namespace std;

class employees 
{
	private:
		static int mcount ,  ecount  ; 
		int eid ;
		string ename, designation;
	public:
		void getinfo(){
			cout<<"Enter the employees id , name and designation (Upper case):";
			cin>>eid>>ename>>designation;
			if(designation == "MANAGER") mcount++;
			if(designation == "ENGINEER") ecount++;
		}
		void show();
};

int employees::mcount =0 ;
int employees::ecount =0 ;

void employees::show(){
	cout<<"There are "<<mcount<<" managers."<<endl;
	cout<<"There are "<<ecount<<" engineers.";
}

int main()
{
	employees e[100];
	int n;
	cout<<"Enter the no of employees:";
	cin>>n;
	for(int i=0;i<n;i++)
	 e[i].getinfo();
	e[1].show();
	cout<<"\nThe total no of employees is "<<n;
	
	return 0;
}
 

