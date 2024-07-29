#include<iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter a number: ";
    cin >> size;
     int array[size];
    for (int i = 0; i < size; i++)
    {cin>>array[i];
    }
    cout<<"1D Array "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;

    int first = 0;
    int second = 0;
   
    //factors 
    for (int i = 2; i < size; i++)
    {if (size%i==0)
    {
        first = i;
        second = size/i;
        break;
    }
    
    }
    cout<<first<<" "<<second<<endl;
    
    int array2 [first][second];
    int index = 0;


    for (int i = 0; i < first; i++)
    {
        for (int j = 0; j < second; j++)
        {
            array2[i][j] = array[index++];
        } 
    }
    cout<<endl;
    cout<<"This is 2D array "<<endl;
    
    for (int i = 0; i < first; i++)
    {
        for (int j = 0; j < second; j++)
        {
            cout<<array2[i][j]<<" ";
        }
        cout<<endl;
    }
    
}