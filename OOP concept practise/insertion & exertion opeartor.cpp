#include<iostream>
using namespace std;
class A{
      int x;
      int y;
      public:
    
      A(){
          x=10;
          y=20;
      }
    
    friend ostream& operator<<(ostream& out , const A& obj);
    
};

ostream& operator<<(ostream& out , const A& obj){
        out<<obj.x<<endl;
        out<<obj.y<<endl;
        return out;
}

class B{
  int x;
  int y;
  public:
  B(){
      x=30;
      y=40;
  } 



   friend ostream& operator<<(ostream& out , const B& obj);

};

ostream& operator<<(ostream& out , const B& obj){
    out << obj.x << endl;
    out << obj.y << endl;
    return out;

  }

int main( ){
    A a;
    B b;

    cout << a<< endl;
    cout << b<< endl;
}