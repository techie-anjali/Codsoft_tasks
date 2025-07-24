//SIMPLE CALCULATOR 
// Develop a calculator program that performs basic arithmetic
// operations such as addition, subtraction, multiplication, and
// division. Allow the user to input two numbers and choose an
// operation to perform.

// SIMPLE CALCULATOR
// Performs addition, subtraction, multiplication, and division.

#include <bits/stdc++.h>
using namespace std;

void sum(int a, int b) {
    cout << "Sum: " << a + b << endl;
}

void sub(int a, int b) {
    cout << "Subtraction: " << a - b << endl;
}

void mul(int a, int b) {
    cout << "Multiplication: " << a * b << endl;
}

void divide(int a, int b) {
    if (b == 0)
        cout << "Error: Division by zero!" << endl;
    else
        cout << "Division: " << a / b << endl;
} 

int main() {
    int a, b;
    char op;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    cout << "Choose your operation (+, -, *, /): ";
    cin >> op;

    switch (op) {
        case '+': sum(a, b); break;
        case '-': sub(a, b); break;
        case '*': mul(a, b); break;
        case '/': divide(a, b); break;
        default: cout << "Invalid operation!" << endl;
    }

    return 0;
}
