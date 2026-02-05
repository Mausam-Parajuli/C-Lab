/*
Program: Given that an EMPLOYEE class contains following members:
data members: Employee number, Employee name, Basic, DA, IT, Net Salary
and print data members. Write a C++ program to read the data of N employee
and compute Net salary of each employee (DA=52% of Basic and Income Tax
(IT) =30% of the gross salary) .
*/
#include<iostream>
using namespace std;

class EMPLOYEE {
	private :
		int eno ;
		string ename ;
		float basic , da , it , netsalary ;
		
	public :
		void getinput(){
			cout<<"Enter eno ename and basic salary respectively:";
			cin>>eno>>ename>>basic;
		}
		void showinfo(){
			cout<<"\nEmployee No : "<<eno<<" Name:"<<ename<<endl<<"Basic salary:"<<basic<<" Daily allowance:"<<da
			<<" Income tax:"<<it<<endl<<" Total salary:"<<netsalary;
		}
		void calculate();
};

void EMPLOYEE::calculate(){
	da = 0.52*basic;
	float gross = basic + da;
	it = 0.3*gross;
	netsalary = gross - it ;
};

int main()
{
	EMPLOYEE E[100];
	int n;
	cout<<"Enter the no of employees :";
	cin>>n;
	for(int i=0;i<n;i++){
		E[i].getinput();
		E[i].calculate();
	}
	for(int i=0;i<n;i++) E[i].showinfo();
	
	return 0;
}

