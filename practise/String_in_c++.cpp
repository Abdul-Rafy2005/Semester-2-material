#include<iostream>
#include<string>
using namespace std;
int main(){
    string a = "hello";
    string b = " world";
    string c = "my firrst program in c++";
    cout<<a.append(b)<<endl<<c<<endl;
    cout << a + " " + b<<endl;
     for (int i = 0; i<5;i++){
       for (int j = 0; j<= i;j++){
        cout<<" *";
       }
       cout<<endl;
     }
    return 0;
}