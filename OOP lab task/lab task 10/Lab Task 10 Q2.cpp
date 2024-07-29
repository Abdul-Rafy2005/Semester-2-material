
#include<iostream>
using namespace std;
// make complex class 
class complex{
    // data member of this class as real & imaginary part of number
      int real;
      int imag;
     
   public : 
    
     // default constructor to initialize data member
     complex(int Real = 0,int Imag = 0): real(Real),imag(Imag) {}
    
    // granting friendship from complex class through friend function
    friend complex addComplex(complex c1, complex c2);

    // member function for displaying real & imaginary part
     void display(){
        cout << real << "+" << imag<<"i"<<endl;
     }
};

// defination of friend function
complex addComplex(complex c1, complex c2){
  
  // introducing a new data member for modified value of real and imaginary data member of object c1 & c2
   
   int real = c1.real + c2.real;
   int imag = c1.imag + c2.imag;

   // returning c3 complex with updated value of real and imaginary data member
   return complex(real,imag);

}
int main(){
    
    // 
    complex c1(5,3);
    complex c2(6,7);
    // assigning updated values to new object of complex class 
    complex c3 = addComplex(c1,c2);
    // displaying updated values through display member function of complex 
    c3.display();
}