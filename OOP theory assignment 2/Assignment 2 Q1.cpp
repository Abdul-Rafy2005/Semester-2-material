#include <iostream>
#include <string>
using namespace std;

class dayType {
    // main attribute
private:
    string *Current_day;

public:
    // Default constructor
    dayType() {
        // initializing day attribute to Sunday
        Current_day = new string;
        *Current_day = "Sun";
    }

    // Parametrized constructor
    dayType(string day) {
        // initialize day with user-defined value
        *Current_day = day;
    }

    // User-defined copy constructor
    dayType(const dayType& object) {
        // copying data from one object to another of the same class
        Current_day = object.Current_day;
    }

    // Setter to set a new value to day
    void SetDay(string Newday) {
        *Current_day = Newday;
    }
 
     // member function to print the current day & const, for  not modifying it
    void PrintDay() const {
        cout << "\nDay is: " << *Current_day << endl;
    }

     // member function to return  the current day & const, for  not modifying it 
    string ReturnDay() const {
        return *Current_day;
    }

    // member function to return tommorrow 
    string ReturnNextDay() const {
        string week[7] = {"Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat"};
        int point_day = 0;
        // checking the current day 
        for (int i = 0; i < 7; i++) {
            if (*Current_day == week[i]) {
                // finding the next day
                point_day = (i + 1) % 7;
                break;
            }
        }
        // returning tommorrow
        return week[point_day];
    }
    

    // member function to return previous day
    string ReturnPreviousDay() const {
        string week[7] = {"Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat"};
        int point_day = 0;
        // checking the current day 
        for (int i = 0; i < 7; i++) {
            if (*Current_day == week[i]) {
                // finding the previous day
                point_day = (i + 6) % 7;
                break;
            }
        }
        // returning previous day 
        return week[point_day];
    }

    // member function to add certain days & then check current day
    string calculatingDay(int add_days) const {
        string week[7] = {"Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat"};
        int point_day = 0;

         // checking the currrnt day 
        for (int i = 0; i < 7; i++) {
            if (*Current_day == week[i]) {
                point_day = (i + add_days) % 7;
                break;
            }
        }
        // returning current day
        return week[point_day];
    }

    // Destructor
    ~dayType() {
        delete Current_day;
        cout << "Destructor Called.\n";
    }

    // member function to dynamically allocate space to object 
    dayType* dynamic_allocate(string Day) {
        // allocating space from heap + assigning a value from parametrize constructor   
        dayType* obj = new dayType(Day); 
        return obj;
    }
};

int main() {

    // creating a pointer of object type
    dayType* object = nullptr;

    char choice;
    do {
        
        cout << "\nTop Menu\n";
        cout << "a. Set the Day\n";
        cout << "b. Print the Day\n";
        cout << "c. Return the Day\n";
        cout << "d. Return the Next day\n";
        cout << "e. Return the Previous day\n";
        cout << "f. Calculate and return the day by adding certain Days\n";
        cout << "g. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; 

        switch (choice){
                
            case 'a':
               { // if object is pointing to anything before 
                if (object != nullptr){
                    // first deleting it 
                    delete object;
                }
                string day;
                // asking for a day to set 
                cout << "\nEnter day to set : ";
                cin >> day;
                // and then assigning a new space through member function and assign the day
                object = object->dynamic_allocate(day);
                break;
                system("cls");
               }

            case 'b':
            system("cls");
                if (object != nullptr){
                    // calling  member function to print day 
                    object->PrintDay();
                    break;
                } else {
                    // if object is pointing to null then display this 
                    cout << "\n\nDay is not set. \n"<<endl;
                    break;
                } 

            case 'c':
            system("cls");
                if (object != nullptr){
                     // calling  member function to return the current day 
                    cout << "\nThe current day is : "<< object->ReturnDay()<<endl;
                     break;
                } else {
                    cout << "\nDay is not set."<<endl;
                     break;
                }
               

            case 'd':
            system("cls");
                if (object != nullptr){
                     // calling  member function to return the tommorrow 
                    cout << "\nThe Tommorrow is : "<< object->ReturnNextDay()<<endl; 
                     break;
                } else {
                    cout << "\nDay is not set."<<endl;
                    break;
                }
                

            case 'e': 
            system("cls");
                if (object != nullptr){ 
                     // calling  member function to return the previous day 
                    cout << "\nThe Previous day was : "<< object->ReturnPreviousDay()<<endl; 
                    break;
                } else {
                    cout << "\nDay is not set."<<endl;
                    break;
                }
                

            case 'f':
            system("cls");
                if (object != nullptr){ 
                    int days;
                    // asking from user to enter the days he wanna add
                    cout << "\nEnter the number of Days you wanna add : ";
                    cin >> days;
                    // sending this days to member function for calculating and then return the current day
                    cout << "\nthe Days is : "<< object->calculatingDay(days)<<endl;
                    break;
                } else {
                    cout << "\nDay is not set."<<endl;
                    break;
                }
                

            case 'g':
            
                // if user wanna exit the program
                if (object != nullptr){
                    // deallocating the space and pointing the pointer to null
                    delete object;
                    object = nullptr;
                    break;
                } else {
                    cout << "Program Exit: "<<endl;
                    break;
                }
                

            default: // for invalid input 
                system("cls");
                cout << "\n\nInvalid Input: \n"<<endl;
                break;
        }
       // this program will run until user enter g
    } while (choice != 'g');

    return 0;
}
