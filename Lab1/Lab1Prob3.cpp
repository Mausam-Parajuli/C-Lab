/*
Problem 3:
Write a program that checks the order of a medicine from a pharmacy store.
The program should read the order quantity and the medicine quantity in the
store. When the order quantity is more than the store quantity, your
program should display the message �No enough quantity�. When the order
quantity is less than the store quantity, you have to check that the order
quantity must be not more than 16 except there is more than 40 items in the
store. The messages that will be displayed in that cases are �Your order is
accepted� OR �You cannot order more than 16 item�
*/
#include<iostream>
using namespace std;

int main()
{
	int order , med ;
	cout<<"Enter the order quantity and medicine quantity respectively :";
	cin>>order>>med;
    if(order>med) cout<<"Not enough quantity.";
    else {
    	if(med<=40) {
    		if(order>16) cout<<"You cannot order more that 16 item.";
    		else cout<<"Order accepted";
		}
		else cout<<"Order accepted";
	}
	
	return 0;
}
