#include <iostream>
using namespace std;

// Function to create and initialize a 3x3 matrix
void initializeMatrix(int matrix[3][3]) {
    matrix[0][0] = 4; matrix[0][1] = 1; matrix[0][2] = 9;
    matrix[1][0] = 8; matrix[1][1] = 6; matrix[1][2] = 2;
    matrix[2][0] = 5; matrix[2][1] = 0; matrix[2][2] = 4;
}

// Function to display the matrix
void displayMatrix(int matrix[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}





int main() {
    int matrix[3][3];
    
    // Initialize the matrix
    initializeMatrix(matrix);
    
    cout << "Original Matrix:" << endl;
    // Display the original matrix
    displayMatrix(matrix);
    
    // Swap the upper triangular half with the lower triangular half
    swapUpperLower(matrix);
    
    cout << "Matrix after swapping upper and lower triangular halves:" << endl;
    // Display the modified matrix
    displayMatrix(matrix);
    
    return 0;
}
