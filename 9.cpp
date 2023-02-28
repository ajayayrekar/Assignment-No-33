/*9. Create a base class called volume. Use this class to store two double type values
that could be used to compute the volume of figures. Derive two specific classes
called cube and sphere from the base shape. Add to the base class, a member
function get_data() to initialise base class data members and another member
function display_volume() to compute and display the volume of figures. Make
display_volume() as a virtual function and redefine this function in the derived
classes to suit their requirements.
Using these three classes, design a program that will accept dimensions of a cube
or a sphere interactively, and display the volume.*/

#include <iostream>
#include <cmath>

using namespace std;

class Volume {
protected:
    double dim1, dim2;

public:
    void get_data() {
        cout << "Enter the dimensions: ";
        cin >> dim1 >> dim2;
    }

    virtual void display_volume() {}
};

class Cube : public Volume {
public:
    void display_volume() override {
        double volume = dim1 * dim2 * dim1;
        cout << "Volume of cube is " << volume << endl;
    }
};

class Sphere : public Volume {
public:
    void display_volume() override {
        double volume = 4.0 / 3.0 * 3.1415 * pow(dim1, 3);
        cout << "Volume of sphere is " << volume << endl;
    }
};

int main() {
    int choice;

    cout << "Enter your choice: 1 for cube, 2 for sphere" << endl;
    cin >> choice;

    Volume* shape;
    if (choice == 1) {
        shape = new Cube();
    } else if (choice == 2) {
        shape = new Sphere();
    }

    shape->get_data();
    shape->display_volume();

    delete shape;
    return 0;
}
