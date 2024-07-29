#include<iostream>
using namespace std;
// class of name complex 
class complex{

    private: // private attributes
    float real_part;
    float imaginary_part;

    public:
   
    complex(){   // default constructor intiliazing attribures to zero
        real_part = 0.0;
        imaginary_part = 0.0;
    }

    // member function as a setter for assigning value to atttributes
    void set(float real_part,float imaginary_part){
        this->real_part = real_part;
        this->imaginary_part = imaginary_part;
    }

    // member function for Displaying real and imaginary part of complex number
    void disp(){
        cout << "real part is: ("<< real_part<<")";
        cout << "  and imaginary part of complex number is: "<<imaginary_part<<endl;
    }

    // member function for adding two complex number and then returning new one 
    complex complex_sum(complex object){
        complex sum;
        // adding real part to real and imaginary to imaginary
        sum.real_part = real_part + object.real_part;
        sum.imaginary_part = imaginary_part + object.imaginary_part;
        return sum;
    }
};
int main(){
    // create three objects from complex
    complex number1,number2,number3;
    // assign value to first two object through setter
    number1.set(1.1,2.2);
    number2.set(3.3,4.4);
    // assigning the new one complex number to third object
    number3 = number1.complex_sum(number2);
    
    // displaying all three objectss
        number1.disp();
        number2.disp();
        number3.disp();
  
}