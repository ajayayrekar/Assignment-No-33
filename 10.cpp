/*10. Create a base class called shape. Use this class to store two double type values that
could be used to compute the area of figures. Derive two specific classes called
square and parallelogram from the base shape. Add to the base class, a member
function get_data() to initialise base class data members and another member
function display_area() to compute and display the area of figures. Make
display_area() as a virtual function and redefine this function in the derived classes to
suit their requirements.
Using these three classes, design a program that will accept dimensions of a
square or a parallelogram interactively, and display the area.*/

#include <iostream>
#include <cmath>

using namespace std;

class Shape {
protected:
    double dim1, dim2;

public:
    void get_data() {
        cout << "Enter the dimensions: ";
        cin >> dim1 >> dim2;
    }

    virtual void display_area() {}
};

class Square : public Shape {
public:
    void display_area() override {
        double area = dim1 * dim1;
        cout << "Area of square is " << area << endl;
    }
};

class Parallelogram : public Shape {
public:
    void display_area() override {
        double area = dim1 * dim2;
        cout << "Area of parallelogram is " << area << endl;
    }
};

int main() {
    int choice;

    cout << "Enter your choice: 1 for square, 2 for parallelogram" << endl;
    cin >> choice;

    Shape* shape;
    if (choice == 1) {
        shape = new Square();
    } else if (choice == 2) {
        shape = new Parallelogram();
    }

    shape->get_data();
    shape->display_area();

    delete shape;
    return 0;
}
