#include<iostream>
using namespace std;
void series(int first,int count);
int main(){
    int first_value = 100;
    int count = 11;
    series(first_value,count);
    return 0;
}
void series(int first,int count){
    if (count == 0) return; 
    cout << first << endl;
    if (count % 2 == 0) first -= 15; 
    series(first + 10 ,count - 1);
}