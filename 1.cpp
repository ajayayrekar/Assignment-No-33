/*1. Create a base class called shape. Use this class to store two double type values that
could be used to compute the area of figures. Derive two specific classes called
triangle and rectangle from the base shape. Add to the base class, a member
function get_data() to initialise base class data members and another member
function display_area() to compute and display the area of figures. Make
display_area() as a virtual function and redefine this function in the derived classes to
suit their requirements.
Using these three classes, design a program that will accept dimensions of a
triangle or a rectangle interactively, and display the area.
Remember the two values given as input will be treated as lengths of two sides in
the case of rectangles, and as base and height in the case of the triangles, and used
as follows:
Area of rectangle = x * y Area of triangle = 1/2 * x * y*/


#include <iostream>

using namespace std;

class Shape {
protected:
    double base;
    double height;

public:
    virtual void get_data() {
        cout << "Enter the base: ";
        cin >> base;
        cout << "Enter the height: ";
        cin >> height;
    }

    virtual void display_area() {
        cout << "Area: " << endl;
    }
};

class Rectangle : public Shape {
public:
    void display_area() {
        double area = base * height;
        cout << "Area of rectangle: " << area << endl;
    }
};

class Triangle : public Shape {
public:
    void display_area() {
        double area = 0.5 * base * height;
        cout << "Area of triangle: " << area << endl;
    }
};

int main() {
    Shape *s;
    int choice;

    do {
        cout << "Enter 1 for Rectangle" << endl;
        cout << "Enter 2 for Triangle" << endl;
        cout << "Enter 3 to exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s = new Rectangle();
                s->get_data();
                s->display_area();
                break;

            case 2:
                s = new Triangle();
                s->get_data();
                s->display_area();
                break;

            case 3:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
