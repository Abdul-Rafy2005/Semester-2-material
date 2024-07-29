#include<iostream>
using namespace std;
class shape{
    public:
    shape(){}
    virtual float Calcarea()=0;
    virtual void display() = 0;
    virtual ~shape(){
        cout<<"Destructor for shape"<<endl;
    }

    friend bool operator > (const shape& obj, const shape& obj2);
};



bool operator > (shape& obj,shape& obj2){
      if (obj.Calcarea() > obj2.Calcarea()){
        return true;
      }
      return false;
}

class circle:public shape{
    float radius;

    public:
    circle(float r){
        radius = r;
    }

    ~circle(){
         cout<<"Destructor for circle"<<endl;
    }
    float Calcarea(){
        return 3.14*radius*radius;
    }

    void display(){
        cout << "Circle with radius: "<< radius <<endl;        
        cout<<"Area : " <<Calcarea()<<endl;
    }
};

class Rectangle: public shape{
    float width, height;

    public:
    Rectangle(float w, float h){
        width = w;
        height = h;
    }


    virtual ~Rectangle(){
        cout<<"Destructor Rectangle"<<endl;
    }

    float Calcarea(){
        return width*height;
    }

    void display(){

        cout << "Rectangle with width: "<< width << " and height: "<< height <<endl;        
        cout<<"Area : " <<Calcarea()<<endl;

    }
};

class Triangle : public shape{
    float base, height;

    public:
    Triangle(float b, float h){
        base = b;
        height = h;
    }

    virtual ~Triangle(){
        cout<<"Destructor Triangle"<<endl;
    }

    float Calcarea(){
        return 0.5*base*height;
    }

    void display(){
        cout << "Triangle with Base: "<< base << " and height: "<<height <<endl;
        cout<<"Area: "<<Calcarea()<<endl;
    }

   

};





int main(){
     circle c1(5);
     Rectangle r1(4,6);
     Triangle t1(3,7);

     shape *  shapes[3];

     shapes[0] = &c1;
     shapes[1] = &r1;
     shapes[2] = &t1; 

     for (int i = 0; i < 3; i++){
         shapes[i]->display();
         cout << endl;
     }   

     if (shapes[0] > shapes [1]){
     
             shapes[0]->display();
             cout << "Has greater area than ";
             shapes[1]->display();
     }
}