
#include<iostream>
#include<string>
using namespace std;
// Declaring Structure for Student Record
struct Student_Data {
    // structure Variablel
    string Student_name;
    int course[3];
};
// declaring function to perform tasks
void Display_data(Student_Data*, int count);
void Change_Marks(Student_Data*);
void Calc_Average_Marks(Student_Data*);

int main() {

    int count;
  // asking user that how many he students he want in record
    cout << "Enter the number of students you want to enroll ";
    cin >> count;
    
    Student_Data student[count];

     // starting loop for getting students name and there scores in courses  
    for (int i = 0; i < count; i++) {
        cin.ignore();
        cout << "Enter student name: ";
        getline(cin,student[i].Student_name);
        for (int j = 0; j < 3; j++) {
            cout << "Enter student marks for course "<< j + 1 << ": ";
            cin >>student[i].course[j];
        }   cout <<endl;
       
    }

    int option = 0;
    // Main Menu
    do {
     system("cls");   
    cout << "\nMenu:\n";
     cout << "1. Display Student Data\n";
    cout << "2. Calculate Average marks\n";
    cout << "3. Change Marks\n";
    cout << "4. Exit\n\n";
    cout << "Please select an Option: ";
     cin >> option;
     cout << "\n";

        switch(option) {
            case 1:
                Display_data(student, count);
                break;
            case 2:
                Calc_Average_Marks(student);
                break;
            case 3:
                Change_Marks(student);
                break;
            
        }
    } while(option == 1  || option == 2 || option == 3);

    return 0;
}

// function for Displaying all student whole records
void Display_data(Student_Data *Student, int count) {
    for (int i = 0; i < count; i++) {
        cout << "Student name: " << Student[i].Student_name << endl;
        for (int j = 0; j < 3; j++) {
        cout << "Student marks for course "<< j + 1 << ": " <<Student[i].course[j] << endl;
        }cout <<endl;        
    }
    cin.ignore();
     getchar();
    system("cls");  
}

// function for changing marks for any course for individual 
void Change_Marks(Student_Data *Student) {
      int Student_number, Course_number;

      cout << "Enter the Student Number: ";
     cin >> Student_number;
      cout << "Enter the course number to change marks: ";
     cin >> Course_number;
      cout << "Enter the updated marks: ";
     cin >> Student[Student_number - 1].course[Course_number - 1];
     cin.ignore();
     getchar();
    system("cls");  
}

// Function for calculating average marks of individual students.
void Calc_Average_Marks(Student_Data *student) {
    int Student_number;
    float Average = 0;

    cout << "Enter the Student number: ";
    cin >> Student_number;

    for (int i = 0; i < 3; i++) {
        Average += student[Student_number-1].course[i];
    }
    Average = Average / 3.0;
    cout << "Average marks is: " << Average<< endl; 
     cin.ignore();
     getchar();
    system("cls");  
}
