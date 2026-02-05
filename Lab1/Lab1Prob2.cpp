/*
Write a program that determines the maximum and the minimum of three
numbers.
*/

#include<iostream>
using namespace std;

class number
{
	public:
		int n1,n2,n3 ;
		void getnum(){
			cout << "Enter three numbers : ";
			cin >> n1 >> n2 >> n3 ;
		}
	void compare(){
		(n1>=n2) ? ((n1>=n3) ? (cout<<n1<<"is the biggest.") : (cout<<n3<<"is the biggest")):
		 ((n2>=n3)? (cout<<n2<<"is the biggest.") : (cout<<n3<<"is the biggest."));
		(n1<=n2) ? ((n1<=n3) ? (cout<<n1<<"is the smallest.") : (cout<<n3<<"is the smallest")):
		 ((n2<=n3)? (cout<<n2<<"is the smallest.") : (cout<<n3<<"is the smallest."));
	}
};
 
int main()
{
	number n;
	n.getnum();
	n.compare();
	
	return 0;
}

