#include<iostream>
#include<conio.h>
using namespace std;
struct car {
    string company;
    string engine;
    int year;
    
};
int main(){
    
    car a,*ptr;
    ptr = &a;

    cout << "enter the car type: ";
    cin >> ptr->company;

    cout << "Enter the car's engine : ";
    cin >> ptr->engine;

    cout <<  "enter car year: ";
    cin >> ptr->year;
    cout << "\n\n\n";
    cout << "Your car's information : "<< endl;
    cout << "Car type : "<< ptr->company<< endl;
    cout << "car's engine : "<< ptr->engine<< endl;
    cout << "car's release year : "<< ptr->year; 
    return 0;
}