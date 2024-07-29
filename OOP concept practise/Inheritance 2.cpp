#include<iostream>
using namespace std;
class vehicle{
	protected:
	string model;
	string company;
	public :
	vehicle(string m = "",string c = "") : model(m),company(c){	}
	void Display_info(){
		cout << "Model is : "<< model<<endl;
		cout << "Company is : "<<company<<endl;
	}

};

class car : public vehicle{ 
	int No_of_door;
	public:
	car(string m = "",string c = "",int door = 0) : vehicle(m,c),No_of_door(door){}
    void Display_info() {
	vehicle::Display_info();
	cout << "Number of Doors : "<<No_of_door<<endl;
	}
};

class truck : public vehicle{
    float payload_capacity;
	public:
	truck(string m = "",string c = "",float payload = 0.0) : vehicle(m,c),payload_capacity(payload){}
	void Display_info() {
		vehicle::Display_info();
		cout << "Payload Capacity in ton : "<<payload_capacity<<endl;
	}

};

class motorcycle : public vehicle{
    int engine_displacement;
	public:
	motorcycle(string m = "",string c = "",int engine = 0) : vehicle(m,c),engine_displacement(engine){}
	void Display_info() {
		vehicle::Display_info();
		cout << " Engine displacement in cc is : "<<engine_displacement<<endl;
	}

};

int main(){
	car a("Corallla Altis","Toyota",4);
	a.Display_info();
}