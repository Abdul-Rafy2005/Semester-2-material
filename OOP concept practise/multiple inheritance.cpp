#include<iostream>
using namespace std;
class base1{
    
    public :
    int x;
    void setx(){
        cout << "Enter value of x: ";
        cin >> x;
    }

    void getx(){
        cout << "the value of x is "<<x<<endl;
    }
};

class base2{
    
    public :
    int y;
    void sety(){
        cout << "Enter value of y: ";
        cin >> y;
    }

    void gety(){
        cout << "the value of y is "<<y<<endl;
    }
};

class derived : public base1 , public base2{
    int z;
    public :
    void add(){
        z = x + y;
    }

    void display(){
        cout << "z is : "<<z<<endl;
    }
};
int main(){
   
   derived obj;
   obj.setx();
   obj.sety();
   obj.add();
   obj.display();
}