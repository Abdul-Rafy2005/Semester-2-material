#include<iostream>
using namespace std;
class a{
    public:
    a(){
        Print(); // non const function can be called in constructor in const object
    }
    int c = 9;
    int print() const {
        return c;
    }

    void Print() {
        cout << "Non const function. "<<endl;
    }
};
int main(){
    
   const a b;
   cout << b.c;
  
}