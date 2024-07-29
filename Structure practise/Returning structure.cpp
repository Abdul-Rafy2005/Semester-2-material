#include<iostream>
using namespace std;

struct fruit{
    int price;
    int amount;
    int total_price;
    bool is_high;
};

fruit compareFruits(fruit a, fruit b);

int main(){
    fruit a, b, t;

    cout << "Enter the price of the first fruit: ";
    cin >> a.price;

    cout << "Enter the amount you want of the first fruit: ";
    cin >> a.amount;

    cout << "Enter the price of the second fruit: ";
    cin >> b.price;

    cout << "Enter the amount you want of the second fruit: ";
    cin >> b.amount;

    t = compareFruits(a, b);

    cout << "\n\nHigh Total Price: " << t.total_price << "\nHigh Amount: " << t.amount << "\nHigh Price: " << t.price << "\n";

    return 0;
}

fruit compareFruits(fruit a, fruit b){
    fruit result;
    a.total_price = a.amount * a.price;
    b.total_price = b.amount * b.price;
    
    if (a.total_price > b.total_price) {result = a;}
    else {result = b;}

    return result;
}
