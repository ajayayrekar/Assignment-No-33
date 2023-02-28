/*4. Create a base class called shape. Use this class to store 2 double type values that
could be used to compute the area of figures. Derive 2 specific classes called triangle
and rectangle from the base shape. Add to the base class a member function
get_data() to initialise base class data members and another member function
display_area() to compute and display the area of figures. Make display_area() as a
virtual function and redefine this function in derived classes to suit their requirements.
Using these 3 classes, design a program that will accept the dimensions of the
shapes interactively and display area.*/

#include <iostream>
using namespace std;

class Shape {
protected:
    double length;
    double breadth;

public:
    virtual void get_data() {
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter breadth: ";
        cin >> breadth;
    }

    virtual void display_area() {
        cout << "Area: " << length * breadth << endl;
    }
};

class Triangle : public Shape {
public:
    void get_data() {
        cout << "Enter base: ";
        cin >> length;
        cout << "Enter height: ";
        cin >> breadth;
    }

    void display_area() {
        cout << "Area: " << 0.5 * length * breadth << endl;
    }
};

class Rectangle : public Shape {
public:
    void display_area() {
        cout << "Area: " << length * breadth << endl;
    }
};

int main() {
    Shape* shape_ptr;
    Triangle tri;
    Rectangle rect;
    int choice;

    cout << "Select shape:" << endl;
    cout << "1. Triangle" << endl;
    cout << "2. Rectangle" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            shape_ptr = &tri;
            break;
        case 2:
            shape_ptr = &rect;
            break;
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }

    shape_ptr->get_data();
    shape_ptr->display_area();

    return 0;
}
