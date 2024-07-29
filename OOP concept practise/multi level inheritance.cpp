#include<iostream>
using namespace std;
class A{
   public : 
   void show (){
    cout << "??"<<endl;

   }  
};

class B : public A{

};

class C : public B{

};
int main(){
    C obj;
    obj.show();  
}