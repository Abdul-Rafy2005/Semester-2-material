#include<iostream>
using namespace std;
class recangle{
    private:
    int length;
    int width;
    public:
    // default constractor
    recangle(){
         length = 0;
         width = 0;
    }
    // parameterize constructor
    recangle(int length,int width){
           this->length = length;
           this->width = width;
    }
    int getter(){
        return length*width;
    }
};
int main(){
     recangle r1; // calling default constructor
     recangle r2(23,45);
    cout << "calling parametrize constructor: "<< r2.getter();
}