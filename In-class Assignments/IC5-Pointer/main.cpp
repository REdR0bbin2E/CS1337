#include <iostream> //getting preprocessor directive
using namespace std;

int main() {
    int value;
    int* ptr = nullptr; // Initialize pointer

    cout << "Enter a value: ";
    cin >> value;

    if (value <= 0) {
        cout << value << " is not a positive number" << endl;
    } else {
        ptr = &value;  // Assigning pointer to value
        *ptr *= 100;   // Multiplying value by 100
        cout << "Value: " << *ptr << endl;
    }

    return 0;
}
