#include<iostream>
#include<string>
using namespace std;
int main(){

    string name;
    cout<<"Enter your name: ";
    cin>>name;
    
    name[2] = 'j';
    cout<<name<<"\n"<<endl;
    cout << name.length();
    return 0;
}