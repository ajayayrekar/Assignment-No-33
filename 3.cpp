/*3. Using the concept of pointers, write a function that swaps the private data values of
two objects of the same class type.*/

#include <iostream>
using namespace std;

class MyClass {
private:
    int x;

public:
    MyClass(int val) : x(val) {}

    void printX() {
        cout << "x = " << x << endl;
    }

    // Swap function using pointers
    friend void swapVals(MyClass* a, MyClass* b) {
        int temp = a->x;
        a->x = b->x;
        b->x = temp;
    }
};

int main() {
    // Create two objects
    MyClass obj1(5);
    MyClass obj2(10);

    // Print original values
    obj1.printX();
    obj2.printX();

    // Swap values using pointer function
    swapVals(&obj1, &obj2);

    // Print new values
    obj1.printX();
    obj2.printX();

    return 0;
}
