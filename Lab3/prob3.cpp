//3. Program to convert Cartesian coordinate to Polar.

#include<iostream>
#include<cmath>
using namespace std;

class polar{
	float rad,ang;
	public:
	polar(){}
	polar(float r,float a):rad(r),ang(a){}
	void show(){
		cout<<"Polar: ( "<<rad<<" , "<<ang<<" )";
	};
};

class cartesian{
	float x,y;
	public:
		cartesian(){}
		cartesian(float a,float b):x(a),y(b){}
		operator polar(){
				float r = sqrt(x*x + y*y);
				float a = atan2(y ,x);
				float b = 180 * a / 3.14159;
				
				return polar(r,b);
		};
		void show(){
			cout<<"Coordinate:"<<"( "<<x<<" , "<<y<<" )";
		};
};

int main(){
	float x,y;
	cout<<"Enter the cartesian coordinates:";
	cin>>x>>y;
	cartesian p(x,y);
    polar po = p;
    po.show();
	
	return 0;
}
