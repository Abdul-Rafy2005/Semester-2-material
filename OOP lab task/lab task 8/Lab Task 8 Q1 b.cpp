#include<iostream>
using namespace std;
class dynamic_array{

    int *pointer;
    int size;

    public:

    dynamic_array(int Size = 0) : size(Size){ }

    dynamic_array(const dynamic_array& obj){
        
        size = obj.size;
        pointer = new int [size];
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
        delete []pointer;
        cout << "Destructor Called\n";
    }
};
int main(){
       dynamic_array obj(5);
       dynamic_array Obj(obj);
       Obj.setter();
       cout << "\nyour Dynamic Array is \n";
       Obj.show();
}