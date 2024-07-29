
#include<iostream>
using namespace std;

class A{

    int *ptr;

    public :
     A(){
        ptr = new int;
        *ptr = 10;
    }

     A(const A& obj){
        // deep copy
        ptr = new int;
        *ptr = *obj.ptr; 
     }
     
     // function for changing value of ptr
     void changeValue(int value ){
        *ptr = value;
     }

     ~A(){
        delete ptr;
     }

     friend ostream& operator<<(ostream& out , const A& obj);

};
ostream& operator<<(ostream& out , const A& obj){
    out << *obj.ptr;
    return out ;

}

int main(){
    A a;
    A b(a);
    cout << a << " " << b << " " <<endl;
    a.changeValue(1);
    cout << a << " " << b << " " <<endl;
    return 0;
}