#include<iostream>
using namespace std;
class data{

    public:
    int x;
    data(){}
    data* dynamic(data* object){
          object = new data;

          return object;
    }
    
};
int main(){

    data *a = nullptr;;
    a = a->dynamic(a);
    a->x = 7;
    cout << a->x;
    delete a;


}
