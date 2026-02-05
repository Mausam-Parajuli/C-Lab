//1. Assume class person stores the Name, Age and ID, class employee
//stores the designation, basic salary, total overtime(hr) in a month
//and hourly rate and class computedSalary stores the total salary of
//the employee. Implement above concept using appropriate inheritance.

#include<iostream>
using namespace std;

class person{
	protected:
		string name;
		int age;
		int id;
};

class employee : protected person{
	protected:
		string designation;
		float bsalary;
		float tovertime;
		float rate;
};

class computedSalary : protected employee {
	protected:
		float tsalary;
	public:
		computedSalary(string n, int a ,int i,string des , float bs , float ot,float r){
			name = n; age = a; id = i; designation = des; bsalary = bs; tovertime =ot; rate =r;
		}
		~computedSalary(){
		}
		int totalsalary(){
			float ot = tovertime * rate ;
			tsalary = bsalary + ot;
		}
		int display(){
			cout<<"Name:\t"<<name<<"\nId:\t"<<id<<"\nAge:\t"<<age<<"\nDesignation:\t"<<designation<<"\nBasicSalary:\t"<<"Rs."<<bsalary<<"\n";
			cout<<"Overtime:\t"<<tovertime<<"hrs"<<"\nRate:\t"<<"Rs."<<rate<<"\nTotalSalary:\t"<<"Rs."<<tsalary;
		}
};

int main(){
	computedSalary obj("HariOm",20,1111,"Manager",15000,9,1500);
	obj.totalsalary();
	obj.display();
	
	return 0;
}

