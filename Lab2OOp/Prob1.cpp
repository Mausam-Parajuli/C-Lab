//1.To write a C++ program to swap two private data members using friend
//functions.

#include <iostream>
using namespace std;

class Data {
private:
    int x;
    int y;

public:
    Data(int a, int b) {
    	x=a; y=b;
	}

    friend void swap(Data& obj);

    void display() {
        cout << "x = " << x << ", y = " << y << std::endl;
    }
};

void swap(Data& obj) {
    swap(obj.x, obj.y);
}

int main() {
	int a,b;
	cout<<"Enter two numbers:";
	cin>>a>>b;
    Data obj(a, b);
    cout << "Before swap: ";
    obj.display();

    swap(obj);
    cout << "After swap: ";
    obj.display();

    return 0;
}
