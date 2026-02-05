// To write a C++ program to manipulate complex numbers using operator overloading.
// (addition,subtraction,multiplication,division)

#include<iostream>
using namespace std;

class complex {
    float real;
    float img;

    public:
        void input(){
            cin >> real >> img;
        }

        void output(){
            if(img < 0){
                cout << real << img << "i";
            } else {
                cout << real << " + " << img << "i";
            }
        }
         
        complex operator+(complex &obj){
            complex c;
            c.real = real + obj.real;
            c.img = img + obj.img;
            return c;
        }
         
        complex operator-(complex &obj){
            complex c;
            c.real = real - obj.real;
            c.img = img - obj.img;
            return c;
        }
         
        complex operator*(complex &obj){
            complex c;
            c.real = real * obj.real - img * obj.img;
            c.img = real * obj.img + img * obj.real;
            return c;
        }
         
        complex operator/(complex &obj){
            complex c;
            float denom = obj.real * obj.real + obj.img * obj.img;
            c.real = (real * obj.real + img * obj.img) / denom;
            c.img = (img * obj.real - real * obj.img) / denom;
            return c;
        }
};

int main(){
    complex c1, c2, sum, diff, prod, quo;
    cout << "Enter the real and imaginary part of the first number: ";
    c1.input();
    cout << "Enter the real and imaginary part of the second number: ";
    c2.input();

    sum = c1 + c2;
    diff = c1 - c2;
    prod = c1 * c2;
    quo = c1 / c2;

    cout<< " Sum : ";
    sum.output();

    cout << endl;
    cout << " Substraction : ";
    diff.output();

    cout << endl;
    cout << " Product :";
    prod.output();
    
    cout << endl;
    cout << " Quotient :";
    quo.output();


    return 0;
}
