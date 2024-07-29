
#include<iostream>
#include<cmath>
using namespace std;
int main(){
float  x1,y1,x2,y2;
// asking for user input
cout << "Enter  x1,y1,x2,y2 : ";
cin>>x1>>y1>>x2>>y2;


// doing inner calculation  according to formula
float difference_of_x = x2 - x1;
float difference_of_y = y2 - y1;

difference_of_x *= difference_of_x;
difference_of_y *= difference_of_y;

float sum = difference_of_x + difference_of_y ; 

float distance = sqrt(sum);

// final distance 
cout << "distance is "<<distance;
    return 0;
}