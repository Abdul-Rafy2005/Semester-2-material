#include<iostream>
using namespace std;
// class of name angle
class angle{
    private:
    // three main attributes ,all of them are pointer because will access space from heap
    int* degree;
    float* minutes;
    char* Direction;
    bool type;

    public:
      // default constructor to initialy initialize member 
      angle() : degree(new int(0)),minutes(new float(0.0)),Direction(new char(' ')),type(new bool(true)) {
      }      

     // parametrize constructor to assign and initialize attributes dynamically
    angle(int degree,float minutes,char Direction){
        this->degree = new int(degree);
        this->minutes = new float(minutes);
        this->Direction = new char(Direction);
    }

    ~angle(){ // destructor for deallocating memory from attributes
        delete degree;
        delete minutes;
        delete Direction;
        cout << "Destructor called."<<endl;
    }

    // copy constructor to copy data from one object to other
    angle (const angle& object){
        degree = new int (*(object.degree));
        minutes = new float (*(object.minutes));
        Direction = new char (*(object.Direction));
        type = object.type;
    }
    
    // member functions declaration
    void Obtain_value();
    void Display();

    // static member function for dynamically allocate object and return to main to initialize a not initializing pointer object
     static angle* createDynamically(int degree,float minutes,char Direction){
        angle* object = new angle(degree,minutes,Direction);
        return object;
    }
};

// member function for inputing the value from user
void angle::Obtain_value(){


    do {

        cout << "Enter angle value in degree : ";
        cin >> *degree;

        if(*degree < 0 || *degree >180) {
            cout << "Invalid value of degree: \n";
        }

    }while(*degree < 0 || *degree >180);
        
        float mins;
        int deg = *degree;

        do {
         
        cout << "Enter angle value in minutes : ";
        cin >> *minutes; 

        mins = *minutes;
        *degree = deg;
        if (mins >= 60) { // checking if minutes are greater than 60 then converting minutes to degree
          
            *degree += (int)(mins / 60);
            *minutes = mins - 60.0 * (int)(mins / 60.0);

        } 

        if(*minutes < 0) {

            cout << "Invalid input for minutes: \n";

        }  else if (*degree >180){

            cout << "Invalid input for minutes.Degree Exceeded 180.\n";

        }

        }while(*minutes < 0 || *degree >180);
        
        do {

        if (*degree > 90) {

            type = false; // setting Longitude

            cout << "Enter direction (E or W): ";
            cin >> *Direction;

            if (*Direction != 'E' && *Direction != 'W'){
                cout << "Invalid Input."<<endl;
            }

        } else {

            type = true; // setting latitude
            
            cout << "Enter direction (N,S,E,W): ";
            cin >> *Direction;
            if (*Direction != 'N' && *Direction != 'S' && *Direction != 'E' && *Direction != 'W'){
            cout << "Invalid Input.\n";
        }
    }


} while (*Direction != 'N' && *Direction != 'S' && *Direction != 'E' && *Direction != 'W');

    }

// member function for formating information and displaying it
void angle::Display(){

        if (*degree == 0 && *minutes == 0){
             cout << "The angle value is : "<<*degree<<"\xF8"<<*minutes<<"'"<< *Direction << " (Center)" <<endl;
             return;
        }
 
        // for checking whether data is about latitude or longitude  
        if (*degree > 90){
            type = false;
        } else {
            type = true;
        }

        cout << "The angle value is : "<<*degree<<"\xF8"<<*minutes<<"'"<< *Direction << (type ? " (Latitude)" : " (Longitude)") <<endl;
    }
int main(){   
        
        // creating pointer object of angle class and assigning it memory from heap 
        angle* object = angle::createDynamically(0,0,'C');
        object->Display();

        char option;
        do{

         cout << "Enter the Angle Value: "<<endl;
         object->Obtain_value(); // inputing value and diplaying it
         object->Display();

         cout << "\nEnter y for onward & n for Exit (y/n): "; // asking for itreation
         cin >> option;

        }while(option != 'n');

        delete object;
}