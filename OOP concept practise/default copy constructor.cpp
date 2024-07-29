
// we use default copy constructor when we do not have a pointer data member in class
// because if we wanna copy pointer through shallow , it will just copy reference , not the pinter itself

// in shallow copy the only member/variable of the object are copied and if the member are pointer,
// only the memory address they are hold are copied,not hte data pointer to those by pointer

#include<iostream>
using namespace std;
class sample{
    int id;

    public:
    void initialize(int x){
        id = x;
    }
    void display(){
        cout << "ID = "<<id<<endl;
    }
};

int main(){
    sample obj1;
    obj1.initialize(10);
    obj1.display();

   // shallow copy
   // copy bit by bit
    sample obj2(obj1);

    obj2.display();
    cout << "after value update."; 

    obj1.initialize(5);
    obj2.display();   
}