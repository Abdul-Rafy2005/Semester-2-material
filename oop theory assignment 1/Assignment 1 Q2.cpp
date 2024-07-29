#include<iostream>
#include<cstdlib>
using namespace std;
// function Prototype
int* Resize_Array(int* arr, int *size, bool checking_opreation);
int* add_new_number(int *arr, int *size);
int* delete_number(int* arr, int *size);
void print_array(int* arr,int size);
void sum_of_array(int* arr, int size);
int main() {
    // initializing pointer and a size variable
    int *arr;
   int size = 5;
   // addressing the address to arr of dynamically allocate array
    arr = new int[size];
    // input random from 0 to 9 in array
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
    }
     
    cout << "Main Menu:" << endl;
    cout << "1. Add new number" << endl;
    cout << "2. Delete a number" << endl;
    cout << "3. Print the array" << endl;
    cout << "4. Print sum of array" << endl;
    cout << "5. Exit Program" << endl;

    int option;
    cout << "Enter your choice: ";
    cin >> option;
     
    // decision opeartor which will call function on the basis of value enter by user
    do {
        switch (option) {
            case 1:
                arr = add_new_number(arr, &size);
                break;
            case 2:
                arr = delete_number(arr, &size);
                break;
            case 3:
                print_array(arr,size);
                break;
            case 4:
                sum_of_array(arr,size);
                break;
            case 5:
            // if user wanna exit function then deallocate array and assign null to pointer 
                delete[] arr;
                arr = NULL;
                exit(0);
                break;
            default:
                cout << "Invalid Input:";
                break;
        }
        cout << "Enter your choice: ";
        cin >> option;
    } while (option != 5);
    
    delete[] arr;
    arr = NULL;
}

// Function for resizing array according to command 
int* Resize_Array(int* arr, int *size, bool checking_opreation) {
    // allocating memory dynamically to a new pointer 
    int *new_arr = new int[*size];
    // special opeartion used for using this function for both increaing or decreasing funcion according to call 
    // if wanna increase size,element will be copy from original to new array 1 less then size 
    int  copy_limit = checking_opreation ? *size - 1 : *size;
    for (int i = 0; i < copy_limit; i++) {
        new_arr[i] = arr[i];
    }
    // deallocating original one and rturning new one with increased size
    delete[] arr;
    return new_arr;
}

// fuction for increaent in size of function
int* add_new_number(int* arr, int *size) {
    int new_number;
    // taking new number
    cout << "Enter the number: ";
    cin >> new_number;
    (*size)++;
    arr = Resize_Array(arr,size,true);
    // allocating the new number to last index to the increamented array
    arr[*size - 1] = new_number;
    return arr;
}

// fuction for decreament in size of array
int* delete_number(int* arr, int *size) {
    int delete_number;
    // taking new number to delete
    cout << "Enter the number to delete: ";
    cin >> delete_number;
    int i;
    // searching for delete number in array
    for (i = 0; i < *size; i++) {
        if (delete_number == arr[i]) {
            break;
        }
    }
    // if didn't found then printing not found
    if (i == *size ) {
        cout << "Number not found in the array." << endl;
        return arr;
    }
    // if found replace with number with content of next index.Do it with all upcoming index
    for (; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    arr = Resize_Array(arr, size,false);
    return arr;
}

// printing the updated array
void print_array(int* arr,int size){
    for (int i = 0; i < size; i++){
        cout << "The element in Index ["<<i<<"] is : " << arr[i] << endl;
    }
}

// printing the sum of content of array
void sum_of_array(int* arr, int size){
    int sum = 0;
    for (int  i = 0; i < size;i++){
        sum += arr[i]; 
    }
    cout << "The Sum of Array is : "<< sum<<endl;
}