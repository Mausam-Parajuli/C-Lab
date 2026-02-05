/*
Create a 'STRING' class which char* and length as data member and overloads ‘+’ ,’=’ and ‘ = = ‘ 
to perform respective operations.
Use constructor and destructor whenever suitable.
*/

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class String {
	private:
		int length;
		char* text;
	public:
		String(string s){
			length = s.size();
			text = new char[length+1];
			text = strcpy(text , s.c_str());
		}
		String(){
			length = 0;
            text = new char[1];
            text[0] = '\0';
		}
		~String(){
			delete[] text;
		}
		void display(){
			cout<<text; 
		}
		String operator+( const String& s){
			String concat ;
			concat.length = length + s.length ;
			concat.text = new char[concat.length + 1];
			concat.text = strcpy(concat.text , text);
			strcat(concat.text , s.text);
			
			return concat;
		}
		String operator==(const String s){
			if(!strcmp(text,s.text )==1) cout<<"Both strings are same";
			else cout<<"They are different.";
		}
		String operator=(const String& s){
			String copy;
			copy.length = length;
			copy.text = new char[copy.length + 1];
			copy.text = strcpy(copy.text, s.text);
			return copy;
		}
};

int main(){
	String s1,s2,s3,s4;
	string s,ss;
	cout<<"Enter the text:";
	cin>>s;
	cout<<"Enter the text:";
	cin>>ss;
	s1 = String(s);
	s2 = String(ss);
	cout<<"The initial strings are :"<<"\n";
	s1.display();
	cout<<"\n";
	s2.display();
	cout<<"\nAfter concatinating :";
	s3 = s1 + s2;
	cout<<"\n";
	s3.display();
	s4 = s3;
	s1 == s2;
	
	
	
	return 0;
}
