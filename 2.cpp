/*2. Extend the above program to display the area of circles. This requires the addition of
a new derived class 'circle' that computes the area of a circle. Remember, for a circle
we need only one value, its radius, but the get_data() function in the base class
requires two values to be passed. (Hint: Make the second argument of get_data()
function as a default one with zero value.)*/

#include <iostream>
#include <cmath>

using namespace std;

class Shape {
protected:
    double base;
    double height;

public:
    virtual void get_data(double b, double h = 0) {
        base = b;
        height = h;
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

class Circle : public Shape {
public:
    void display_area() {
        double area = M_PI * base * base;
        cout << "Area of circle: " << area << endl;
    }
};

int main() {
    Shape *s;
    int choice;

    do {
        cout << "Enter 1 for Rectangle" << endl;
        cout << "Enter 2 for Triangle" << endl;
        cout << "Enter 3 for Circle" << endl;
        cout << "Enter 4 to exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s = new Rectangle();
                s->get_data(0);
                s->get_data(s->base, s->height);
                s->display_area();
                break;

            case 2:
                s = new Triangle();
                s->get_data(0);
                s->get_data(s->base, s->height);
                s->display_area();
                break;

            case 3:
                s = new Circle();
                s->get_data(0, 0);
                cout << "Enter the radius: ";
                cin >> s->base;
                s->display_area();
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
