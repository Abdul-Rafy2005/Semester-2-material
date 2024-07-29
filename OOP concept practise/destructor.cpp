#include<iostream>
using namespace std;
class des{
    public:
    des(){
      cout << "construct object: "<<endl;
    }

    ~des(){
     cout << "object destory: ";
    }
};
int main(){
  des t1;
  t1.~des();
}