#include<iostream>
using namespace std;
class A{


    public:
    int x;
    int y;
    A(){
        x = 1;
        y = 1;
    }

   A& operator++(){
    x++;
    y++;
    return *this;
   }

 friend ostream& operator<<(ostream & out , const A & a);

};

ostream& operator<<(ostream &out , const A & a){
             out << a.x << endl << a.y << endl;
             return out;
}

int main () {

    A abc;
    cout << abc.x << endl << abc.y <<endl;

    cout << ++abc;
}