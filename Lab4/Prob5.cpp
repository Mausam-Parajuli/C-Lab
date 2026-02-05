/*Write a main () function that creates an instance object of Auto called Car, which has the
following initial data: there is a quantity of five(5) on inventory, and two(2) on reorder;
the price per unit is $15,545.91, and the description is that of the car obtained from the
Toyota. Initialize the object Car, and print out all its vital facts.
b. A Transmission is purchased from Aztec Inc., and must be inventoried. There are 25 of
them, with 10 more on reorder. Their price is $1789.98. Instantiate and initialize an
object for Transmission, and provide the same information.*/

#include <iostream>
#include <string>
using namespace std;

 class inventory{
 	protected:
 		int quantity;
 		int reorder;
 		float price;
 		string description;
 	public:
 		inventory(int q, int r, float p, string d){
 			quantity =q;
			reorder =r;
			price = p;
 			description = d;
		 }; 
		 void display(){
		 	cout<<"\nQuantity:\t"<<quantity;
		 	cout<<"\nReorder:\t"<<reorder;
		 	cout<<"\nPrice:\t$"<<price;
		 	cout<<"\nDescription:\t"<<description;
		 }
 };
class Auto : public inventory{
	string company;
 	public:
 		Auto (int q,int r,float p,string d,string c): inventory(q,r,p,d){
		 company = c;
		 };
		void display(){
			cout<<"Company:\t"<<company;
			inventory::display();
		}
 };
 class transmission : public inventory{
 	string dealer;
 	public:
 		transmission(int q,int r,float p,string d,string de): inventory(q,r,p,d) {
		 dealer = de;
		 };
		void display(){
			cout<<"\n\nTransmission\n\n";
			cout<<"Dealer:\t"<<dealer;
			inventory::display();
		}
 };
 
 int main(){
 	Auto car(5,2,15545.95,"By Toyota","Toyota");
 	car.display();
 	transmission trans(25,10,1789.98,"By Toyota","Aztec Inc.");
 	trans.display();
 	return 0;
 }
