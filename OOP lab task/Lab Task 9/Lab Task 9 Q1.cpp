#include<iostream>
using namespace std;


class Animal{
    protected : 
    string  name;
    int age;
    public :
    Animal(string Name = " ",int Age = 1) : name(Name),age(Age) {}
    void speak(){ }
    

};

class Bird : public Animal{
   float wingLength;
   public :
   Bird(string Name = " ",int AGE = 1,float WingLength = 0.0) : wingLength(WingLength),Animal(Name,AGE){}
  
  
   void speak (){
      cout << "My name is : "<< name <<endl;
      cout << "My age is : "<< age << endl;
      cout << "My ling length is : "<<wingLength<<endl; 
      cout << "I am bird and I can sing...\n";
   }

};

class Reptile : public Animal {
  string habitat;

  public : 
  Reptile(string Name = " ",int AGE = 1,string Habitat = " ") : habitat(Habitat),Animal(Name,AGE){}
 
 
  void speak(){
      cout << "My name is : "<< name <<endl;
      cout << "My age is : "<< age << endl;
      cout << "i live in : "<<habitat<<endl;
      cout << "I am reptile. I can creep\n";
  }

};
int main(){

    Bird a("Hen",2,2.4);
    a.speak();
    Reptile b("Crocodile",4,"forest");
    b.speak();
    
}