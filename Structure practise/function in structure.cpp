#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    string rol_no;
    int age;
    
    void Display(string name,string roll,int age){
         cout <<"your name: "<< name <<endl;
         cout << "your roll number: "<< roll <<endl;
         cout << "your age: "<< age<<endl;
    }

    
};

int main() {

    Student s;
    s.name = "Abdul Rafy";
    s.rol_no = "23p-0560";
    s.age = 18;
    s.Display(s.name,s.rol_no,s.age);


    return 0;
}
