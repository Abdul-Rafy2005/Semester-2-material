#include<iostream>
using namespace std;
int main(){
    int protein,iteration;
     do{
        cout << "Enter protein in grams: ";
        cin >> protein;
        
        iteration = 0;
        // restriction to user for inputing invalid value
        // like if value is negative or non numeric
        if (cin.fail() || protein < 0) {
            cout << "Invalid input."<<endl;
            // built in function for clear input
            cin.clear();
            // built in function to skip any other character if remain in buffer
            // setting limit to 100 , if there are 100 char in buffer , it will skip them 
            cin.ignore(100, '\n');  
            iteration++;
            continue;
        }
    } while (iteration);
}