/*
To write a C++ program to overload all relational operators to compare US currency with Nepalese currency.
Use conversion rate $1=NRs 101.36(Note: make two classes to represent each currency)
*/

#include<iostream>

using namespace std;

class dollars;


class Rs{
    float amount;

    public:
    	Rs(float amt){
            amount = amt;
        }

        void show(){
            cout << amount;
        }

        // Overloading all opeartors
        friend bool operator>(Rs, dollars);
        friend bool operator<(Rs, dollars);
        friend bool operator>=(Rs, dollars);
        friend bool operator<=(Rs, dollars);
        friend bool operator==(Rs, dollars);
        friend bool operator!=(Rs, dollars);
        
        friend bool operator>(dollars, Rs);
        friend bool operator<(dollars, Rs);
        friend bool operator>=(dollars, Rs);
        friend bool operator<=(dollars, Rs);
        friend bool operator==(dollars, Rs);
        friend bool operator!=(dollars, Rs);
};


class dollars{
    float amount;

    public:
        dollars(float amt){
            amount = amt;
        }

        void show(){
            cout << amount;
        }

        //Overloading all operators        
        friend bool operator>(dollars, Rs);
        friend bool operator<(dollars, Rs);
        friend bool operator>=(dollars, Rs);
        friend bool operator<=(dollars, Rs);
        friend bool operator==(dollars, Rs);
        friend bool operator!=(dollars, Rs);
        
        friend bool operator>(Rs, dollars);
        friend bool operator<(Rs, dollars);
        friend bool operator>=(Rs, dollars);
        friend bool operator<=(Rs, dollars);
        friend bool operator==(Rs, dollars);
        friend bool operator!=(Rs, dollars);
};

// Overloading for comparing rupees to dollars
bool operator>(Rs r, dollars d){
    return (r.amount > d.amount * 101.36 * 101.36);
}
bool operator<(Rs r, dollars d){
    return (r.amount < d.amount * 101.36);
}
bool operator>=(Rs r, dollars d){
    return (r.amount >= d.amount * 101.36);
}
bool operator<=(Rs r, dollars d){
    return (r.amount <= d.amount * 101.36);
}
bool operator==(Rs r, dollars d){
    return (r.amount == d.amount * 101.36);
}
bool operator!=(Rs r, dollars d){
    return (r.amount != d.amount * 101.36);
}

// Overloading for comparing dolalrs to rupees
bool operator>(dollars d, Rs r){
    return (d.amount * 101.36 > r.amount);
}
bool operator<(dollars d, Rs r){
    return (d.amount * 101.36 < r.amount);
}
bool operator>=(dollars d, Rs r){
    return (d.amount * 101.36 >= r.amount);
}
bool operator<=(dollars d, Rs r){
    return (d.amount * 101.36 <= r.amount);
}
bool operator==(dollars d, Rs r){
    return (d.amount * 101.36 == r.amount);
}
bool operator!=(dollars d, Rs r){
    return (d.amount * 101.36 != r.amount);
}

int main(){
    float r, d;
    cout << "Enter the amount in rupees and dollars";
    cin >> r >> d;
    Rs r1(r);
    dollars d1(d);
    
    if (d1 > r1)
    	cout << "Dollar is greater";
    else 
    	cout << "Rupees is greater";
}
