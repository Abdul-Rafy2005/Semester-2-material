#include<iostream>
using namespace std;
char c[7][11] = { "OOP-Final", "OOP" ,"Exam" , "Students"," lazy" ,"2023" ,"programmer" };
char* add(char* ptr) {
return ptr + 11;
}
char* sub(char* ptr) {
return ptr - 11;
}
int main()
{
char* mystery = c[4];
cout<< mystery << endl;
cout<< sub(mystery)[2] << endl;
mystery = sub(mystery);
cout<< mystery << endl;
cout<< sub(mystery) + 1 << endl;
cout<< add(add(mystery)) + 13 << endl;
cout<< *add(add(mystery)) << endl;
return 0;
}
