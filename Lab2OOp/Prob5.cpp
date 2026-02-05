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
			strcpy(text , s.c_str());			
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
		String operator+( String& s){
			String concat ;
			concat.length = length + s.length ;
			concat.text = new char[concat.length + 1];
			strcpy(concat.text , text);
			strcat(concat.text , s.text);
			
			return concat;
		}
		bool operator==(const String s){
			if(!strcmp(text,s.text )==1)
			 return true;
			else
				return false;
		}
		String operator=(const String& s){
			String copy;
			copy.length = length;
			copy.text = new char[copy.length + 1];
			strcpy(copy.text, s.text);
			return copy;
		}
};

int main(){
	string s,ss;
	cout<<"Enter the text:";
	cin>>s;
	cout<<"Enter the text:";
	cin>>ss;
	String s1(s);
	String s2(ss);
	cout<<"The initial strings are :"<<"\n";
	s1.display();
	cout<<"\n";
	s2.display();
	cout<<"\nAfter concatinating :";
	String s3 = s1 + s2;
	cout<<"\n";
	s3.display();
	if(s1 == s2){
        cout << "Yes , they are same ." << endl;
        s1.display();
    } else {
        cout << "No they are not same ." << endl;
        s1.display();
        s2.display();
    }
	 
	s1 == s2;
	
	
	
	return 0;
}
