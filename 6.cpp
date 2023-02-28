/*6. Extend above to display the area of circles. For a circle,only one value is needed i.e.
radius but in get_data() function 2 values are passed.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    double dim1, dim2;

public:
    Shape(double d1=0, double d2=0) : dim1(d1), dim2(d2) {}

    virtual double area() {
        cout << "Undefined shape!" << endl;
        return 0;
    }

    void get_data() {
        cout << "Enter dimensions: ";
        cin >> dim1 >> dim2;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(double l=0, double w=0) : Shape(l, w) {}

    double area() {
        return dim1 * dim2;
    }
};

class Triangle : public Shape {
public:
    Triangle(double b=0, double h=0) : Shape(b, h) {}

    double area() {
        return 0.5 * dim1 * dim2;
    }
};

class Circle : public Shape {
public:
    Circle(double r=0) : Shape(r) {}

    double area() {
        return M_PI * dim1 * dim1;
    }
};

int main() {
    Shape *shape;
    int choice;

    cout << "Enter choice (1 = rectangle, 2 = triangle, 3 = circle): ";
    cin >> choice;

    switch (choice) {
        case 1:
            shape = new Rectangle();
            break;
        case 2:
            shape = new Triangle();
            break;
        case 3:
            shape = new Circle();
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 0;
    }

    shape->get_data();

    double area = shape->area();
    cout << "Area: " << area << endl;

    delete shape;

    return 0;
}
