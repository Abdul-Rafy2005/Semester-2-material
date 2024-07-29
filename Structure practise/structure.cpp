#include<iostream>
using namespace std;
struct oop{
    string name;
    int marks;
};
void function (oop*);
int main(){

    oop abc,*bilal;
    bilal = &abc;
    function(&abc); 
    cout << bilal->name<< endl;
    cout << bilal->marks;  
}
void function(oop *abc){

    getline(cin,abc->name);
    cin >> abc->marks;
}