#include<iostream>
using namespace std;
class base{
    protected:
    int x,y;
    public:
    void set(){
        cout << "Enter the value of x : ";
        cin >> x;

        cout << "Enter the value of y : ";
        cin >> y;
    }

    void display(){
        cout << "the value of x : " << x<<endl;

        cout << "the value of y : "<<y<<endl;
    }
};

class derived1 : public virtual base{
    
};

class derived2 : public virtual base{

};

class derived_derived : public derived1,public derived2 {
     
};
int main(){
  derived_derived object;
  object.set();
  object.display();

}