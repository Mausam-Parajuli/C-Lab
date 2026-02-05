/*
Create a 'MATRIX' class of size m X n. Overload the ‘+’ operator to
Add two MATRIX objects. Write a main function to implement it.
*/

#include <iostream>
using namespace std;

class Matrix
{
    int row, col;
    int mat[20][20];

public:
    void input(int r,int c)
    {
    	row = r ; col = c;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> mat[i][j];
            }
        }
    }

    Matrix operator+(Matrix &obj)
    {   
	        Matrix result;
	        result.row = obj.row;
	        result.col = obj.col;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    result.mat[i][j] = mat[i][j] + obj.mat[i][j];
                }
            }
            return result;
    }


    void show()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
	Matrix m1,m2,m3;
    int r, c;
    cout << "Enter the rows and columns of the matrices: ";
    cin >> r >> c;
    cout << "Enter the matrix A: ";
    m1.input(r,c);
    cout << "Enter the matrix B: ";
    m2.input(r,c);
    m3 = m1 + m2;
    cout << "The sum of the matrices is: " << endl;
    m3.show();
    return 0;
}
