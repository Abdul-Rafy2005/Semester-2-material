#include<iostream>
using namespace std;

class Shapes { // base class for different shapes

public:

    Shapes() {}

    virtual ~Shapes() { // Use virtual destructor to allow proper delete of derived class resources
        cout << "Destructor Called for Shapes Class." << endl;
    }

    virtual double area() = 0; // pure virtual , do nothing, just template for his child class
};


class Shapes_2D {

public:

    Shapes_2D() {}

    virtual ~Shapes_2D() { // Use virtual destructor to allow proper delete of derived class resources
        cout << "Destructor Called for 2D Shapes Class." << endl;
    }

    virtual double area() = 0;  // pure virtual , do nothing, just template for his child class

};


class Shapes_3D {

public:

    Shapes_3D() {}

    virtual ~Shapes_3D() {  // Use virtual destructor to allow proper delete of derived class resources
        cout << "Destructor Called for 3D Shapes Class." << endl;
    }

    virtual double area() = 0;  // pure virtuals , do nothing, just template for their child class
    virtual double volume() = 0;  
};


class Circle : public Shapes_2D {

    int radius;

public:

    Circle(int Radius = 1) : radius(Radius) {} //  initializing value of radius through constructor

     ~Circle() {
        cout << "Destructor Called for Circle Class." << endl;
    }

    double area() { // member function for returning area of circle
        return 3.14 * radius * radius;
    }
};


class Square : public Shapes_2D {

    float side;

public:

     Square(float Side = 1) : side(Side) {}  //  initializing value of side through constructor
    
      ~Square() {
        cout << "Destructor Called for Square Class." << endl;
    }

       double area() {  // member function for returning area of square
        return side * side;
    }

};

class Cube : public Shapes_3D {

       float length, width, height;

public:
      //  initializing value of length, width, height through constructor
  Cube(float Length = 1, float Width = 1, float Height = 1) : length(Length), width(Width), height(Height) {}
   
      ~Cube() {
        cout << "Destructor Called for Cube Class." << endl;
    }
    
      double area() {  // member function for returning area of cube
        return 6 * length * length;
    }

   double volume() {   // member function for returning volume of cube
        return length * width * height;
    }
};

class Pyramid : public Shapes_3D {

      float base, height;

public:

      //  initializing value of base, height through constructor
      Pyramid(float Base = 1, float Height = 1) : base(Base), height(Height) {}

      ~Pyramid() {
        cout << "Destructor Called for Pyramid Class." << endl;
    }

      double area() { // member function for returning area of pyramid
        return (base * height) / 2.0;
    }

       double volume() {   // member function for returning volume of pyramid
        return (0.33) * height * base * base;
    }

};

int main() {

    // declaraing a array of pointer of size 2 of type shape 2d class
    Shapes_2D* arr[2];

    int radius;
    cout << "Enter The value of radius for circle: ";
    cin >> radius ;
    arr[0] = new Circle(radius); // assigning circle object with user defined value dynamically at 0 index 

    float side;
    cout << "Enter The value of side for square: ";
    cin >> side ;
    arr[1] = new Square(side); // assigning Square object with user defined value dynamically at 0 index 

    // declaraing a array of pointer of size 2 of type shape 3d class
    Shapes_3D* Arr[2];

    float length,width,height;

    cout << "Enter the length for cube : ";
    cin >> length;

    cout << "Enter the width for cube : ";
    cin >> width;

    cout << "Enter the Height for cube: ";
    cin >> height;

    Arr[0] = new Cube(length, width, height); // assigning cube object with user defined value dynamically at 0 index 
  
    float base;

    cout << "Enter the base of pyramid: ";
    cin >> base;

    cout << "Enter the Height for pyramid: ";
    cin >> height;

    Arr[1] = new Pyramid(base, height);  // assigning pyramid object with user defined value dynamically at 0 index 
 
    cout << "\n\n";
    for (int i = 0; i < 2; i++) { // displaying area of each 2d shapes

        if (i == 0)
            cout << "Area of Circle is : " << arr[i]->area() << endl;
        else
            cout << "Area of Square is : " << arr[i]->area() << endl;
    }

    for (int i = 0; i < 2; i++) {  // displaying area of each 2d shapes

        if (i == 0) {
            cout << "Area of Cube is : " << Arr[i]->area() << endl;
            cout << "Volume of Cube is : " << Arr[i]->volume() << endl;
        }
        else {
            cout << "Area of Pyramid is : " << Arr[i]->area() << endl;
            cout << "Volume of Pyramid is : " << Arr[i]->volume() << endl;
        }
    }
    
    for (int i = 0; i < 2; i++) {

        delete arr[i];
        delete Arr[i];

    }

    return 0;
}
