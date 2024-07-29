#include<iostream>
#include<string>
using namespace std;
struct record {
    int money;
};
int main(){
    record person[5];
    int i,sum = 0;
    for (i =0 ; i < 5; i++){
        cin >> person[i].money;
        sum += person[i].money;
    }
    cout << "total money of these 5 person is " << sum;
    return 0;
}