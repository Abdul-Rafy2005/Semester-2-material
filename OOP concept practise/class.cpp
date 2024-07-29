#include<iostream>
using namespace std;
class area{
    private : 
    int length,radius;
    float area;
    public:
    // default constructor 
    area (){
        length = 0;
        radius = 0;
        area = 0.0;

    }
    // parametrized constructor 
    area (int l,int r){
          length = l;
          radius = r;
    }

    void set_l(int l){
        length = l;
    }

    void set_r(int r){
        radius = r;
    }

    float  get_l(){
        area = length*radius *0.5
        return area;
    
}
};
int main(){
	area circle(12,10);
    cout << "area is "<< circle.get_l;
    

	
}