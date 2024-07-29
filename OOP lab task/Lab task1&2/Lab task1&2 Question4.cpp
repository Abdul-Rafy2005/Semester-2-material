#include<iostream>
using namespace std;

int main(){
   int days,pennies,total_earning;
   pennies = 1;
   total_earning = 1;
   cout << "enter days";
   cin >> days;
   cout << "the person is earning " << pennies << "in a 1st day"<<endl;
    for (int i = 1;i<= days - 1; i++){
        pennies *= 2;
        total_earning +=pennies;
        
        cout << "the person is earning " << pennies << "in a "<< i+1 << "day"<<endl;
    }

     cout << "the total amount he earned is " << total_earning;

    return 0;
}