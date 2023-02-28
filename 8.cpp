/*8. Create a base class called proof. Use this class to store two int type values that could
be used to prove that triangle is a right angled triangle. Create a class compute
which will determine whether a triangle is a right angled triangle.

Using these classes, design a program that will accept dimensions of a triangle, and
display the result.
(Summary: Prove that triangle is a right angled triangle using pythagoras theorem).*/

#include <iostream>
#include <cmath>

using namespace std;

class Proof {
protected:
    int a, b;

public:
    Proof(int A=0, int B=0) : a(A), b(B) {}
};

class Compute : public Proof {
public:
    Compute(int A=0, int B=0) : Proof(A, B) {}

    bool isRightAngled() {
        int c = sqrt(a*a + b*b);
        return (c*c == a*a + b*b);
    }
};

int main() {
    int a, b;
    cout << "Enter the lengths of the two sides of the triangle: ";
    cin >> a >> b;

    Compute triangle(a, b);
    bool isRight = triangle.isRightAngled();

    if (isRight) {
        cout << "The triangle is a right-angled triangle." << endl;
    } else {
        cout << "The triangle is not a right-angled triangle." << endl;
    }

    return 0;
}
