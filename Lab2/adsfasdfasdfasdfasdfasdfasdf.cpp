/*
To write a C++ program to overload all relational operators to compare US currency with Nepalese currency.
Use conversion rate $1=NRs 101.36(Note: make two classes to represent each currency)
*/

#include<iostream>
using namespace std;

class dollars;

class rupees{
	public:
    	float amount;
	public:
		rupees(float Rs){
			amount = Rs;
		}
		~rupees(){
		}
		friend class dollars;
		friend bool operator>(rupees rs, dollars doll);
		friend bool operator<(rupees rs, dollars doll); 
		friend bool operator<=(rupees rs, dollars doll);
		friend bool operator<=(rupees rs, dollars doll);
		friend bool operator==(rupees rs, dollars doll);
		friend bool operator!=(rupees rs, dollars doll);		
};

class dollars{
	private:
	 float amount;
	public:
		dollars(float doll){
			amount = doll;
		}
		~dollars(){
		}
		friend class rupees;
		friend bool operator>(rupees rs, dollars doll);
		friend bool operator<(rupees rs, dollars doll); 
		friend bool operator<=(rupees rs, dollars doll);
		friend bool operator<=(rupees rs, dollars doll);
		friend bool operator==(rupees rs, dollars doll);
		friend bool operator!=(rupees rs, dollars doll);
		
};

bool operator>(rupees rs, dollars doll){
	float amount = 101.36 *doll.amount;
	if(amount>rs.amount)   true;
 
}
bool operator<(rupees rs, dollars doll){
	float amount = 101.36 *doll.amount;
	if(amount<rs.amount) return true;
	else return 0;
}
bool operator>=(rupees rs, dollars doll){
	float amount = 101.36 *doll.amount;
	if(amount>=rs.amount) return true;
	else return 0;
}
bool operator<=(rupees rs, dollars doll){
	float amount = 101.36 *doll.amount;
	if(amount<=rs.amount) return true;
	else return 0;
}
bool operator==(rupees rs, dollars doll){
	float amount = 101.36 *doll.amount;
	if(amount==rs.amount) return true;
	else return 0;
}
bool operator!=(rupees rs, dollars doll){
	float amount = 101.36 *doll.amount;
	if(amount!=rs.amount) return true;
	else return false;
}

int main(){
	dollars doll;
	rupees rs;
	float rs , $;
	cout<<"Enter the rupees and dollars amount respectively:";
	cin>>rs>>$;
	rs = rupees(rs);
	doll = dollars($);
	cout<<"Now after the comparision of the two we find out that :";
	rs>doll;
	rs<doll;
	rs>=doll;
	rs<=doll;
	rs==doll;
	rs!=doll;
	
	
	return 0;
}

