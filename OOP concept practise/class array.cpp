#include<iostream>
using namespace std;
class Student{
   private:
   string name;
   int mark;
   float gpa;
   public:
    Student(){
        mark = 0;
    }
    Student(string name,int mark,float gpa){
          this->name = name;
          this->mark = mark;
          this->gpa = gpa;
    }

    void setter(string name){
        this->name = name;
    }
    int mark(int mark){
       this->mark = mark;
    }
    void gpa(flaot gpa){
         this->gpa = gpa;
    }


    string getter(){
        return name;
    }
    int Mark(){
        return mark;
    }
    float Gpa(){
        return gpa;
    }
    ~Student(){
        cout << "object destory: ";
    }
};

void display(Student boy[]){
    for (int i = 0 ; i < 3 ; i++){
        cout << "Student name : "<< boy[i].getter()<<endl;
          cout << "Student mark : "<< boy[i].Mark()<<endl;
            cout << "Student name : "<< boy[i].Gpa()<<endl;
    }
}
int main(){
   
   string name;
   int mark;
   float gpa;
   Student boy[3]; 
   
        cout << "Student name : ";
         getline(cin,name);
          cout << "Student mark : ";
           cin >> mark;
            cout << "Student gpa : ";
             cin >> gpa;
    for (int i = 0 ; i < 3 ; i++){
        cout << "Enter Student name : ";
        cin >> name;
        boy[i].setter(name);
          cout << "Student mark : ";
          cin >> mark;
          boy[i].mark(mark);
            cout << "Student gpa : ";
            cin >> gpa;
          boy[i].gpa(gpa);
    }
    display(boy);
}