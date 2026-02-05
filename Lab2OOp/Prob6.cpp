/*
Modify class in the previous program to work with compile time memory allocation i.e. with char[].
*/

#include<iostream>
#include<cstring>
 

#define MAX_SIZE 100

using namespace std;

class String{
    char text[MAX_SIZE];
    int length;

    public:
        String(string s){
            length = s.size();
             
            strcpy(text, s.c_str());
        }

        String(){};

        String operator+(String s2){
            String t;
            strcpy(t.text, text);
            strcat(t.text, s2.text);
            return t;
        }

        void operator=(String t){
            strcpy(text, t.text);
        }

        bool operator == (String &o){
            return(!strcmp(text, o.text));
        }

        void display(){
            cout << text << endl;
        }
};

int main(){
	string s,ss;
	cout<<"Enter the string:";
	cin>>s;
	cout<<"Enter another string:";
	cin>>ss;
    String str1(s);
    String str2(ss);
    

    if(str1 == str2){
        cout << "Yes , they are same ." << endl;
        str1.display();
    } else {
        cout << "No they are not same ." << endl;
        str1.display();
        str2.display();
    }
	String str3 = str1 + str2;
    cout<<"After concatination :";
    str3.display(); 
    return 0;
}
