/*7. Create a base class called Matrix. Use this class to store 4 int type values that could
be used to calculate determinants and create matrices. Create class
calculate_determinant which will calculate the determinant of a matrix.
Using these classes, calculate the determinant of the matrix.*/

#include <iostream>

using namespace std;

class Matrix {
protected:
    int a, b, c, d;

public:
    Matrix(int A=0, int B=0, int C=0, int D=0) : a(A), b(B), c(C), d(D) {}
};

class CalculateDeterminant : public Matrix {
public:
    CalculateDeterminant(int A=0, int B=0, int C=0, int D=0) : Matrix(A, B, C, D) {}

    int determinant() {
        return (a*d - b*c);
    }
};

int main() {
    int a, b, c, d;
    cout << "Enter the values of the 2x2 matrix:" << endl;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "c: "; cin >> c;
    cout << "d: "; cin >> d;

    CalculateDeterminant mat(a, b, c, d);
    int det = mat.determinant();

    cout << "The determinant of the matrix is " << det << endl;

    return 0;
}
