#include "Complex.h"

// Constructor with default values
Complex::Complex(double rreal, double imag) {
    real = rreal;
    imaginary = imag;
}

// Constructor that parses string like "1.9 10.01"
Complex::Complex(string input) {
    istringstream iss(input);
    iss >> real >> imaginary;
}

// Destructor (not strictly needed here, but defined since it's in header)
Complex::~Complex() {
    cout << "Destructor called" << endl;
}

// Getters
double Complex::getReal() {
    return real;
}

double Complex::getImaginary() {
    return imaginary;
}

// Setters
void Complex::setReal(double rreal) {
    real = rreal;
}

void Complex::setImaginary(double imag) {
    imaginary = imag;
}

// Addition: c = a + b
Complex Complex::operator+(const Complex &second) const {
    return Complex(real + second.real, imaginary + second.imaginary);
}

// Compound addition: a += b
void Complex::operator+=(const Complex &second) {
    real += second.real;
    imaginary += second.imaginary;
}

// Conjugate: ~a → (a, -b)
Complex Complex::operator~() {
    return Complex(real, -imaginary);
}

// Input: cin >> obj
istream& operator>>(istream& input, Complex &object) {
    input >> object.real >> object.imaginary;
    return input;
}

// Output: cout << obj
ostream& operator<<(ostream& output, const Complex &object) {
    output << "(" << object.real << "," << object.imaginary << ")";
    return output;
    
    
}


