#include<iostream>
using namespace std;  // one base class & multiple derived class from it
class person{
    protected:
    string name;
    int age;
    string email;
    public:
    void set(){
        cout << "enter name : ";
        getline(cin>>ws,name);
        cout << "enter age : ";
        cin >> age;
        
        cout << "enter email : ";
        getline(cin>>ws,email);

    }

    void get(){
        cout << "name : "<<name<<endl;
        cout << "Age : " << age << endl;
        cout << "Email : " << email << endl;
    }
};

class student : public person {
    protected : 
    string CGPA ;
    public :

    void setcgpa(){
        set();
        cout << "Enter cgpa : ";
        getline(cin,CGPA);
    }
    void getcgpa(){
        get();
        cout << "CGPA is : "<<CGPA << endl;
    }
};

class teacher : public person {
    protected : 
    string qualification ;
    public :

    void setqualification(){
        cout << "Enter qualification : ";
        getline(cin,qualification);
    }
    void getqualification(){
        cout << "qualification is : "<<qualification << endl;
    }
};
int main(){
   
   student s;
   s.setcgpa();
   cout << "\n\n\n";
   s.getcgpa();
   
}