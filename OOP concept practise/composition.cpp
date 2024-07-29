#include<iostream>
using namespace std;
class account { 
int accountID, initBalance; 
public:
account(int ID, int Bal) : accountID(ID), initBalance(Bal) { }
void display(){
cout <<" Account ID: "<< accountID << " and balance: "<<initBalance << endl;
} };
class Employee { 
string name;
double salary;
account ac;
public:
Employee(string n, double sal, int id, int bal) : ac(id,bal), name(n),salary(sal) {}
void display() {
cout <<"Name: "<< name << " Salary: "<<salary<<endl;
ac.display();
}
};
int main() {
Employee E1("Gareth Thomas", 200000,139, 250000);
E1.display();
}



