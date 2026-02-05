//3. Modify Q.2 to add base class sales that holds an array of three
//floats so that it can record the dollar sales of a particular
//publication for the last three months. Include getdata() function to
//get three Sales amount from the user and a putdata() function to
//display sales figures. Alter the book and tape classes so they are
//derived from both publication and sales. An object of class book or
//tape should input and output sales data along with its other data.

#include<iostream>
using namespace std;

class sales{
	protected:
		float $sales[3];
	public:
		void getdata(){
 			cout<<"Enter the sales of last three months:";
 			for(int i=0;i<3;i++){
 				cin>>$sales[i];
			 }
		 }
		void putdata(){
		 	cout<<"\nThe sales of last three months are ";
		 	for(int i=0;i<3;i++) cout<<"$"<<$sales[i]<<" ";
		 }
};

 class publication{
 	protected:
 		string title;
 		float price;
 	public:
 		void getdata(){
 			cout<<"Enter the title :";
 			getline(cin,title);
 			cout<<"Enter the price :";
 			cin>>price;
		 }
		void putdata(){
		 	cout<<"\nTitle:\t"<<title<<"\nPrice:\t"<<"Rs."<<price;
		 }
 };
 
 class book: public publication,public sales{
 	protected:
 		int pcount;
 	public: 
 		void getdata(){
 			publication::getdata();
 			sales::getdata();
 			cout<<"Enter the page count:";
 			cin>>pcount;
		 }
		void putdata(){
			publication::putdata();
			sales::putdata();
		 	cout<<"\nPagecount:\t"<<pcount;
		 }
 };
 
 class tape: public publication,public sales{
 	protected:
 		int minutes;
 	public:
 		 void getdata(){
 			cout<<"Enter the length of audiobook in minutes:";
 			cin>>minutes;
		 }
		 void putdata(){
		 	cout<<"\nAudiobook lenght:\t"<<minutes<<"min";
		 }
 };

int main(){ 
	tape audio;
	book physical;
	physical.getdata();
	audio.getdata();
	physical.putdata();
	audio.putdata();
	
	
	return 0;
}


