#include<iostream>
#include<string>
using namespace std;
class parent{
    public:
     virtual void show(){  // for modifying this function in child Class 
        cout << "Parent function"<<endl;
    }
};

class child : public parent{
    public:
     void show(){
        cout << "Child function"<<endl;
    }
};
int main(){

   parent *ptr;

   child c;
   ptr = &c;
 
   ptr->show();

}