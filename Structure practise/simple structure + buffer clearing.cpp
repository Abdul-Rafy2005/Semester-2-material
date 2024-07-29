#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
struct student
{
  string name;
  string rol_nu;
  int Class;
  char Grade;

};
int main(){
    student a,b;
    cout <<"For student 1"<<endl<< "Enter your name ";
    getline(cin,a.name);
    cout << "Enter your roll number ";
    getline(cin,a.rol_nu);
    cout  << "Enter your class: ";
    cin >>  a.Class;
     cin.ignore();
    cout <<"Enter your grade: ";
    cin >>  a.Grade;


 cout <<"For student 2"<<endl<< "Enter your name ";
    cin.ignore();
    getline(cin,b.name);
    cout << "Enter your roll number ";
    getline(cin,b.rol_nu);
    cout  << "Enter your class ";
    cin >>  b.Class;
    cin.ignore();
    cout <<"Enter your grade: ";
    cin >>  b.Grade;


    cout <<"For student 1"<<endl<<"your name: "<< a.name <<endl<< "your roll number: "<< a.rol_nu <<endl<< "your class: "<< a.Class<<endl<<"your grade: "<< a.Grade<<endl;
    cout << "\n\n";
    cout <<"For student 2"<<endl<<"your name: "<< b.name <<endl << "your roll number: "<< b.rol_nu <<endl<< "your class: "<< b.Class<<endl<<"your grade: "<< b.Grade;     
    
    return 0;
}