#include<iostream>
using namespace std;
class dynamic_array{

    char *pointer;
     int size;
    public:

    dynamic_array(int Size) : size(Size){
        pointer = new char[size];
        for (int i = 0; i < size ; i++){
            pointer[i] = 0;
        }
    }

    void setter(){
        for (int i = 0; i < size ; i++){
            cout << "Enter Value for Index "<<i <<". ";
            cin >> pointer[i];
        }
    }

    void show(){
        for (int i = 0; i < size ; i++){
            cout << " Value for Index "<<i <<" . "<<pointer[i]<<endl;
        }
    }

    ~dynamic_array(){
        delete [] pointer;
        cout << "Destructor Called\n";
    }
};
int main(){
       dynamic_array obj(5);
       obj.setter();
       cout << "\nyour Dynamic Array is \n";
       obj.show();
}