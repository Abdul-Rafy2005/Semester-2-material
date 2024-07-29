#include<iostream>
using namespace std;
// function Prototype
int** Creating_Matrices(int rows,int columns);
int** input_For_Matrices(int** matrix,int rows,int columns);
void Matrices_Printing(int** matrix,int rows,int columns);
int** Matrices_Addition(int **matrix1,int **matrix2,int rows,int columns);
int** Matrices_Substraction(int **matrix1,int **matrix2,int rows,int columns);
int** Matrices_Multiplication(int **matrix1,int **matrix2,int rows,int columns);
int** Matrices_Transpose(int **matrix,int rows,int columns);
void Matrices_delete(int **matrix,int rows);
int main(){
  // initializing variable for rows and columns
    int rows,columns;
    // starting loop to take value of row and column until user put the same value of both
    do {
    cout << "Enter the number of rows for Matrices: ";
    cin >> rows;

    cout << "Enter the number of columns for Matrices: ";
    cin >> columns;
    
    if (rows != columns){
      cout << "Invalid Input.\nThe number of rows and columns of Both Matrices should be equal for Addition and Substraction Opeartion\nAlso as well as in some aspects for Multiplication \nSo again input value and vlaue should be equal : \n"<< endl;
    }
    
  } while (rows != columns);

    // initializing pointer 
    int **Matrix1;
    // calling function for creating matrices dynamically 
    Matrix1 = Creating_Matrices(rows,columns);

    int **Matrix2;
    Matrix2 = Creating_Matrices(rows,columns);

    // calling function for inputing value in matrices
    cout << "Enter element of Matrix 1: "<<endl;
    Matrix1 = input_For_Matrices(Matrix1,rows,columns);
    
    cout << "Enter element of Matrix 2: "<<endl;
    Matrix2 = input_For_Matrices(Matrix2,rows,columns);

  // calling function for printing matrices
    cout << "Matrix1 is : \n";
    Matrices_Printing(Matrix1,rows,columns);

    cout << "Matrix2 is : \n";
    Matrices_Printing(Matrix2,rows,columns);

  // initializing pointer and giving the address of addition matrices to it
    int** addition = Matrices_Addition(Matrix1,Matrix2,rows,columns);

    cout << "The addition of Marices is : "<<endl;
    Matrices_Printing(addition,rows,columns);
    Matrices_delete(addition,rows);

  // initializing pointer and giving the address of substration matrices to it
    int **substraction = Matrices_Substraction(Matrix1,Matrix2,rows,columns);

    cout << "the Substraction of Matrices is :"<<endl;
  // printing and deallocating function
    Matrices_Printing(substraction,rows,columns);
    Matrices_delete(substraction,rows);

  // initializing pointer and giving the address of product matrices to it  
    int **Product = Matrices_Multiplication(Matrix1,Matrix2,rows,columns);

  // printing and deallocating function
    cout << "the Multiplication of Matrices is :"<<endl;
    Matrices_Printing(Product,rows,columns);
    Matrices_delete(Product,rows);

  // initializing pointer and giving the address of transpose matrices to it
    int **transpose = Matrices_Transpose(Matrix1,rows,columns);
    
  // printing and deallocating function
    cout << "the transpose of Matrices 1 is :"<<endl;
    Matrices_Printing(transpose,rows,columns);
    Matrices_delete(transpose,rows);

    transpose = Matrices_Transpose(Matrix2,rows,columns);

    cout << "the transpose of Matrices 2 is :"<<endl;
    Matrices_Printing(transpose,rows,columns);
    Matrices_delete(transpose,rows);

    Matrices_delete(Matrix1, rows);
    Matrices_delete(Matrix2, rows);
    
    return 0;
}

// function for creating matrices dynamically 
int** Creating_Matrices(int rows, int columns){
    int **allocate = new int* [rows];
    for (int i =0 ; i< rows;i++){
        allocate[i] = new int [columns];
    }
    return allocate;
}

// function for inptting value in matrices
int** input_For_Matrices(int** matrix,int rows,int columns){
    
    for (int i = 0;i<rows;i++){
        for (int j = 0;j < columns ; j++){
            cout << "Index ["<<i<<"]["<<j<<"] : ";
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// function for printing matrices
void Matrices_Printing(int** matrix,int rows,int columns){
    for (int i = 0;i<rows;i++){
        for (int j = 0;j < columns ; j++){
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
}

// function for adding two matrices
int** Matrices_Addition(int **matrix1,int **matrix2,int rows,int columns){
    
      int **Sum = new int *[rows];
      for (int i =0 ; i< rows;i++){
        Sum [i] = new int [columns];
    }
      for (int j = 0;j<rows;j++){
        for (int k = 0;k<columns;k++){
            Sum[j][k] = matrix1[j][k] + matrix2[j][k];
        }
      }
    return Sum;  
}

// function for substracting two matrices
int** Matrices_Substraction(int **matrix1,int **matrix2,int rows,int columns){
    
      int **substraction = new int *[rows];
      for (int i =0 ; i< rows;i++){
        substraction [i] = new int [columns];
    }
      for (int j = 0;j<rows;j++){
        for (int k = 0;k<columns;k++){
            substraction[j][k] = matrix1[j][k] - matrix2[j][k];
        }
      }
    return substraction;  

}

// function for multiplicating two matrices
int** Matrices_Multiplication(int **matrix1,int **matrix2,int rows,int columns){
    
      int **product = new int *[rows];
      for (int i =0 ; i< rows;i++){
        product [i] = new int [columns];
    }
     for (int j = 0;j<rows;j++){
     for (int k =0;k<columns;k++){
          product[j][k] = 0;
     for (int l = 0;l<columns;l++){
       product[j][k] += matrix1[j][l] * matrix2[l][k];
       }        
      }
    }  
    return product;
}

// function for Matrix transpose
int** Matrices_Transpose(int **matrix,int rows,int columns){

      int **transpose = new int* [columns];
      for (int i =0 ; i< columns;i++){
        transpose [i] = new int [rows];
    }
      for (int i = 0; i < rows; i++) {
       for (int j = 0; j < columns; j++) {
        transpose[j][i] = matrix[i][j];
    }
  }
  return transpose; 
}

// function for deleting/deallocating matrix
void Matrices_delete(int **matrix,int rows){
      
      for (int i = 0 ;i<rows;i++){
        delete [] matrix[i];
      }
      delete [] matrix;
      matrix = nullptr;
}