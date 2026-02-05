//2.Create a class publication that stores the title and price of a
//publication. From this class derive two classes:book, which adds a
//page count and tape, which adds a playing time in minutes. Each of
//these three classes should have getdata() function to get its data
//from the user at the keyboard and putdata() function to display its
//data.

#include<iostream>
#include<string>
using namespace std;

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
 
 class book: public publication{
 	protected:
 		int pcount;
 	public: 
 		void getdata(){
 			publication::getdata();
 			cout<<"Enter the page count:";
 			cin>>pcount;
		 }
		void putdata(){
			publication::putdata();
		 	cout<<"\nPagecount:\t"<<pcount;
		 }
 };
 
 class tape: public publication{
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

