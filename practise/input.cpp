#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class Employee{
    private:
    string name;
    int id;
    public:
    Employee(){
        id = 0;
    }
    void input(){
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter id: ";
        cin >> id;

    }
    void output(){
        cout << "employee name : "<< name<<endl;
        cout << "empployee id: "<< id;

    }
};
int main(){
    Employee emp;
    emp.input();
    emp.output();
}