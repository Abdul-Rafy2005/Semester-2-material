#include<iostream>
using namespace std;
int main(){
    string name;
    cout << "Enter your name: ";
    cin >> name;
     int size = name.length();

    for (int i = 0; i  < size / 2;i++ ){

         if (name[i] != name [size - i - 1]){
                   cout << "NOt palindrome"<<endl;}
          else {
            cout << "Palindrome\n";
         }

      }
}
