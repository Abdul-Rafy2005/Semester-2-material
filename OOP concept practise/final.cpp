#include<iostream>
using namespace std;

class A {
    ~A(){
        cout << 'a'<<endl;
    }
};

class B : private A{
    public:
    ~B(){
        cout << 'B' << endl;
    }
};
int main(){

    B b;
    A a;

    {
        B * bptr;
        A * Aptr = &a;
    }
 
}