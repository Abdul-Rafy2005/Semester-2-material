#include<iostream>
#include<string>
using namespace std;

// class for date of birth
class date_of_birth {
    // its data member birthday 
    int day;
    int month;
    int year;

public:
//default parametrize constructor for initializing data member of class 
    date_of_birth(int Day = 0, int Month = 0, int Year = 0) : day(Day), month(Month), year(Year) {}


   // member function for return day of birth    
    int getday(){
        return day;
    }

   // member function for return month of birth
    int getMonth() {
        return month;
    }

   // member function for return year of birth    
    int getyear(){
        return year;
    }
};


// class for contact 
class Contact {
    // data member of contact
    string name;
    int phone_number;
    string email;

    // making a object of date of birth class for accessing it through this object
    date_of_birth d_o_b;

public:
   //default parametrize constructor for initializing data member of class 
   // also initializing object of date of birth class 
    Contact(string Name = "", int Phone_number = 0, string Email = "", int Day = 0, int Month = 0, int Year = 0)
        : name(Name), phone_number(Phone_number), email(Email), d_o_b(Day, Month, Year) {}

   // member function for return name       
    string getName() {
        return name;
    }

   // member function for return email   
    string getEmail() {
        return email;
    }

   // member function for return phone number    
    int getPhoneNumber() {
        return phone_number;
    }

   // member function for accessing month of birth  
    int getMonthOfBirth() {
        // calling member function of date of birth class for accessing month
        return d_o_b.getMonth();
    }

   // member function for accessing day of birth        
    int getday() {
        // calling member function of date of birth class for accessing day
       return  d_o_b.getday();
    }

   // member function for accessing  year of birth   
    int getyear() {
        // calling member function of date of birth class for accessing year
        return  d_o_b.getyear();
    }
};

//  class of contact book
class ContactBook {
     // setting size static, because of assigning value directly(hard code) as this is now belong to class 
    static const int size = 2;
    // make a array of object of contact class for accessing different contact
    Contact contacts[size];

public:
// default parametrize constructor
// accessing a array of object through parameter
    ContactBook(Contact c[]) {
        // and assigning its value of contacts array(actual one)
        for (int i = 0; i < size; i++) {
            contacts[i] = c[i];
        }
    }

// member function for checking month of birthday of contact
    void print_contacts(int month) {
        for (int i = 0; i < size; i++) {
            // if any contact's month match with the user provided month
            if (contacts[i].getMonthOfBirth() == month) {
                // we are printing its data 
                cout << contacts[i].getName() << " has birthday in this month." << endl;
                cout << "His phone number: " << contacts->getPhoneNumber()<<endl;
                cout << "His email: "<<contacts->getEmail()<<endl;
                cout << "His birthday: "<<contacts->getday()<<"/"<<contacts->getMonthOfBirth()<<"/"<<contacts->getyear()<<endl<<endl<<endl;
            }
        }
    }
};


int main() {
    string name, email;
    int day, month, year, phone_number;

     // array of object of contact class
    Contact contacts[2];

    // getting data from user for differnt index of array
    for (int i = 0; i < 2; i++) {
        cout << "Enter your name: ";
        getline(cin, name);
        
        cout << "Enter your phone number: ";
        cin >> phone_number;

        cout << "Enter your email: ";
        cin.ignore(); 
        getline(cin, email);

        cout << "Enter your day, month, and year of birth: ";
        cin >> day >> month >> year;

        cin.ignore(); 
        // setting data provided by user in array ,index wise 
        contacts[i] = Contact(name, phone_number, email, day, month, year);
    }

    // make  a object of contactbook and send the array of contact in it through parameter
    ContactBook book(contacts);

    // getting month of birth from user for searching
    int search_Month;
    cout << "Enter the month number to search for birthdays: ";
    cin >> search_Month;

    // calling member function for searching contact of matching this month
    book.print_contacts(search_Month);

    return 0;
}
