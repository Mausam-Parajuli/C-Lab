 

/*
Program to convert Nepalese Currency (Rupees and Paisa) to US Currency (Dollar and Cents). (Rs. 98.51=1$)
*/

#include<iostream>

using namespace std;

class rupees{
    int rs, paisa;

    public:
        rupees(int ru, int pa){
            rs=ru;
            paisa=pa;
        }

        int getRupees(){
            return rs;
        }
        int getPaisa(){
            return paisa;
        }

        void show(){
            cout << "Rs." << rs << "." << paisa;
        }
};

class Dollars{
    int dollar, cent;
    public:
        Dollars(){}
        Dollars(rupees r){
            float totalRupees = static_cast<float>(r.getPaisa())/100 + r.getRupees();
            float totalDollars = totalRupees / 98.51;
            dollar = static_cast<int>(totalDollars);
            cent = (totalDollars-dollar) * 100;
        }

        void show(){
            cout << "$" << dollar << "."<< cent;
        }

};

int main(){
	int a,b;
	cout<<"Enter the Rs and paisa :";
	cin>>a>>b;
    rupees r(a, b);
    Dollars d;
    d = r;
    r.show();
    cout << endl;
    d.show();
    return 0;
}
