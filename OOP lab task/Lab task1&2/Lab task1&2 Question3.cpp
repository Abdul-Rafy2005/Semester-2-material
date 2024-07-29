#include<iostream>
using namespace std;
int main(){
    int pennies,dimes,nickels,quarters;

    cout << "Enter the amount in pennies,dimes,nickels,quarters"; 
    cin>>pennies>>dimes>>nickels>>quarters;

    float  sum1,sum2,sum3,sum4;
    
    sum1 = pennies / 100.0;

    sum2 = dimes / 20.0;

    sum3 = nickels / 10.0;

    sum4 = quarters / 4.0;

    float dollar = sum1 + sum2 + sum3 + sum4;

    if (dollar == 1.0) {
        cout<< "congrates you win: " ;
    }
     else if (dollar < 1.0){
        cout<< "amount is less than one dollar " ;
    }  else if (dollar > 1.0){
        cout << "amount is greater than one dollar " ;
    }

    return 0;
}