#include<iostream>
using namespace std;
class Student{
    protected:
    string name;
    int age;
    int Rollnumber;
    float cgpa;

    public:
    Student(string n = " ",int a = 0,int r = 0,float c = 0.0) : name(n),age(a),Rollnumber(r),cgpa(c){
        cout << "base class constructor called\n";
    }
    void showcpga(){
        cout << "Cgpa is : "<< cgpa<<endl;
    }

};

class ugStudent : public Student{
    string fyptitle;
    string supervisorname;
    public:
    ugStudent(string n = " ",int a = 0,int r = 0,float c = 0.0,string fyp = " ",string supervisor = " ") : Student(n,a,r,c),fyptitle(fyp),supervisorname(supervisor){
        cout << "ug constructor called\n";
    }

    void showfyptitle(){
        cout << name<<" : FYPtitle is : "<< fyptitle <<endl;
    }
};

class pgStudent : public Student{
    string thesistitle;
    string Supervisorname;
    public:
    pgStudent(string n = " ",int a = 0,int r = 0,float c = 0.0,string thesis = " ",string Supervisor = " ") : Student(n,a,r,c), thesistitle(thesis),Supervisorname(Supervisor){
        cout << "pg constructor called\n";
    }

    void showfyptitle(){
        cout <<  name<<" : Thesis title is : "<< thesistitle <<endl;
    }
};

int main(){
    pgStudent pg("rafay",18,0560,2.8,"platform","mazhar");
    pg.showfyptitle();
}