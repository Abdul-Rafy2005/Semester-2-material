#include<iostream>
using namespace std;
// class of Rectangle
class Rectangle{

    private: // private attributes  of class
    float width;
    float length;
    float Area;

    public:

    Rectangle(){ // default constuctor is initializing attributes to zero
        width = 0.0;
        length = 0.0;
        Area = 0.0;
    }

    // using setter to set value of length
    void setlength(float length){
        this->length = length;
    }
    // using setter to set value of width
    void setwidth(float width){
        this->width = width;
    }

    // Method for calculating perimeter of rectangle and return it 
    float perimeter(){
        float perimeter;
        perimeter = (length + width) * 2;
        return perimeter;
    }

    // Method for calculating area of rectangle and return it 
    float area(){
        Area = length * width;
        return Area;
    }

    // Method for displaying length and width of rectangle
    void display(){
        cout <<"length is : "<<length<<endl;
        cout << "width is : "<< width<<endl;
    }
    // Method for checking area of two rectangle
    int samearea(Rectangle object){
        if (Area == object.Area){
            // return it 1 if area is same 
                 return 1;
        } else {
                // and if not then returning 0
                 return 0;
        }
    }

};
int main(){
    
    // creating two object of Rectangle
      Rectangle rectangle1,rectangle2;

      // setting value of length and width in both object through setter
      rectangle1.setlength(5);
      rectangle1.setwidth(2.5);
      rectangle2.setlength(5);
      rectangle2.setwidth(18.9);

     // displaying object one
      rectangle1.display();
      cout << "Area of Reactangle1 is : "<<rectangle1.area()<<endl;
      cout << "Perimeter of Reactangle1 is : "<<rectangle1.perimeter()<<endl;

     // displaying object two 
      rectangle2.display();
      cout << "Area of Reactangle2 is : "<<rectangle2.area()<<endl;
      cout << "Perimeter of Reactangle2 is : "<<rectangle2.perimeter()<<endl;
     
     // checking whether both object has same area or not 
      if (rectangle1.samearea(rectangle2)){
        cout<< "Both Rectangle have the same area.\n"<<endl;
      } else {
        cout << "Rectangle have the different area.\n"<<endl;
      }

     // again assigning new value to object 1
      rectangle1.setlength(15);
      rectangle1.setwidth(6.3);
   
     // displaying object one
      rectangle1.display();
      cout << "Area of Reactangle1 is : "<<rectangle1.area()<<endl;
      cout << "Perimeter of Reactangle1 is : "<<rectangle1.perimeter()<<endl;

    // displaying object two 
      rectangle2.display();
      cout << "Area of Reactangle2 is : "<<rectangle2.area()<<endl;
      cout << "Perimeter of Reactangle2 is : "<<rectangle2.perimeter()<<endl;

     // again checking whether both object has same area or not 
      if (rectangle1.samearea(rectangle2)){
        cout<< "Both Rectangle have the same area.\n"<<endl;
      } else {
        cout << "Rectangle have the different area.\n"<<endl;
      }      
}