#include<iostream>
using namespace std;
struct inner{
    int alpha;
};
struct outer{
    inner inner_most;
};
int main(){
    outer outer_most;
    cin >> outer_most.inner_most.alpha;
    cout << outer_most.inner_most.alpha;
}