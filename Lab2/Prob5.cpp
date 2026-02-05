#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class String {
private:
    int length;
    char* text;
public:
    String(string s) {
        length = s.size();
        text = new char[length + 1];
        strcpy(text, s.c_str());
    }
    String() {
        
    }
    String(const String& other) {
        length = other.length;
        text = new char[length + 1];
        strcpy(text, other.text);
    }
    ~String() {
        delete[] text;
    }

    String operator+(const String& s) {
        String concat;
        concat.length = length + s.length;
        concat.text = new char[concat.length + 1];
        strcpy(concat.text, text);
        strcat(concat.text, s.text);
        return concat;
    }

    String& operator=(const String& s) {
        if (this != &s) {
            delete[] text;
            length = s.length;
            text = new char[length + 1];
            strcpy(text, s.text);
        }
        return *this;
    }

    bool operator==(const String& s) {
        return strcmp(text, s.text) == 0;
    }
};

int main() {
    String s1, s2, s3, s4;
    string s, ss;
    cout << "Enter the text: ";
    getline(cin, s);
    cout << "Enter the text: ";
    getline(cin, ss);
    s1 = String(s);
    s2 = String(ss);
    cout << "After concatinating :" << endl;
    s3 = s1 + s2;
    cout << s3.text << endl;

    return 0;
}
