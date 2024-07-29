#include <iostream>
using namespace std;

// Function to calculate factorial
int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to calculate combination
int combination(int i, int j) {
    return factorial(i) / (factorial(j) * factorial(i - j));
}

// Function to print Pascal's Triangle
void printPascalTriangle(int numRows) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            cout << combination(i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> rows;
    printPascalTriangle(rows);
    return 0;
}
