#include<iostream>
using namespace std;
void duplicate(int arr[],int size){
       int current_number;
       int count;
       for (int i = 0; i < size; i++){
        current_number = arr[i];
        count = 0;
        for (int j = 0; j < size;j++){
            if(arr[j] == current_number){
                count++;
            }
        }
        if (count > 1){
        cout << current_number << " is duplicate in array."<<endl;
    }

    }
}
int main(){
    int size = 6;
    int arr[6] = {1,2,4,2,5,4};
     duplicate(arr,size);
}