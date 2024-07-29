#include<iostream>
using namespace std;

// passing as argument
// 1D arr passing
void print(int arr[]){
    cout << endl << *arr + 1;
}
int main(){
    int arr[5] = {1,2,3,4,5};
     print(arr);

}


// passing as pointer
// 1D arr passing
// void print(int *arr){
//     cout << endl << arr[2];
// }
// int main(){
//     int arr[5] = {1,2,3,4,5};
//      print(arr);

// }


// passing as a reference
// void print(int (&arr)[1][2]){
//     cout << arr[0][1];
// }
// int main(){
//     int arr[1][2];
//     for (int i = 0 ;i < 1;i++){
//         for (int j = 0; j < 2 ; j++){
//             cin >> arr[i][j];
//         }
//     }
//     print(arr);
// }


//passing as a pointer
// void print(int (*arr)[2]){
//     cout << *(*arr + 1);
// }
// int main(){
//     int arr[1][2];
//     for (int i = 0 ;i < 1;i++){
//         for (int j = 0; j < 2 ; j++){
//             cin >> arr[i][j];
//         }
//     }
//     print(arr);
// }

