#include<iostream>
using namespace std;
int main(){

 // initializing a variable to number of rows
    int rows;
    cout << "Enter the number of rows : ";
    cin >> rows;
    
    // initializing a pointer and addressing it the address of dynamically allocate array
    int *columns = new int [rows];
    // initializing a double pointer and addressing it the address of dynamically allocate 2d array
    int** arr2d = new int* [rows];

    // inputing the number of columns per rows
    cout << "Enter the number of values you want in each row : \n";
    for (int i = 0 ; i < rows; i++){
       cin >>  columns[i];
    }
     
    // allocating dynamically 1d array in 2d array
    for (int j = 0 ; j < rows ; j++){
        arr2d [j] = new int [columns[j]];
    }
    
    // Entering the content in 2D array 
    for (int k = 0 ; k < rows ; k++){
         cout << "Enter the value for row : "<< k + 1 << endl;
        for (int l = 0; l < columns[k];l++){
            cin >> arr2d[k][l];
        }
    }
    
    // Printing The content of 2D array
    cout << "The Final Matrix is : \n";

    for (int m = 0 ; m < rows ; m++){
        for (int n = 0; n < columns[m];n++){
            cout << arr2d[m][n]<<" ";
        }
        cout << endl;
    }

 // deallocating  the 1d array (rows) and then deleting the 2D array
    for (int i = 0; i < rows ; i++){
        delete [] arr2d[i];
    }
    delete [] arr2d;
    delete [] columns;
    arr2d = NULL;
    columns = NULL;
}
