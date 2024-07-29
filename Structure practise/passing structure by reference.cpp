#include<iostream>
#include<string>
using namespace std;
struct fruit{
    string type;
    int price;
    int amount;
    int totat_price;
};
void display(fruit*);
int main(){
    fruit a;
    cout << "Enter the type of fruit: ";
    cin >> a.type;

    cout << "Enter the price of fruit: ";
    cin >> a.price;

    cout << "Enter the amount you want of fruit: ";
    cin >> a.amount;

    display(&a);

    cout <<"Our Total price of fruit is : "<< a.totat_price;
    return 0;

}

void display(fruit *a){
    cout << "\n\nBill is \n";
    cout << "Fruit type: "<< a->type << endl;
    cout << "Fruit price: "<< a->price<< endl;
    cout << "Fruit amount: "<< a->amount << endl;
    a->totat_price = a->amount * a->price;
}