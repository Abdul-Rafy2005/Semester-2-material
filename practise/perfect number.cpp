#include<iostream>
using namespace std;
int main(){

    int number,sum,divider;
    sum = 0;
    divider = 2;
    cout<<"Enter a number: ";
    cin>>number;
    int middle;
    middle = number / 2; 
    for (;divider<=middle;divider++){
        if (number % divider == 0) sum += divider;
    }
    if (sum == number) cout << number << "is a perfect number";
    else cout<< number << " is a perfect number";
    return 0;    
}