/*
Create a 'STRING' class which char* and length as data member and overloads ‘+’ ,’=’ and ‘ = = ‘ 
to perform respective operations.
Use constructor and destructor whenever suitable.
*/

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class String{
	char* text;
	int length;
	public:
		String(string s){
			length = strlen(s);
			text = new char[ length + 1];
			strcpy(text , s.c_str());
		}
		String(){
		}
		~String(){
			delete[]text;
		}
		
};
int main(){
	String s1,s2,s3,s4;
    string s,ss;
	cout<<"Enter a string: ";
	cin>>s;
	s1=String(s);
	cout<<"Enter a string: ";
	cin>>ss;
	s2=String(ss);
	
	return 0;
}
