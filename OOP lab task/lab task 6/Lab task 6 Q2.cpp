#include<iostream>
using namespace std;
// database for employee
class Employee{

     private:
     string name;
     string job_title;
     float salary;
     int worked_hour;
     int pay;
     int ID;

     public:
     Employee(){
        ID = 0;
        worked_hour = 0;
        salary = 0.0;
        pay= 0;
    }
    
    void setter(string name,int ID,string job_title,int worked_hour,int pay){
        this->name = name;
        this->ID = ID;
        this->job_title = job_title;
        this->worked_hour = worked_hour;
        this->pay = pay;
    }
    
    string getname(){
        return name;
    }
    int getID(){
        return ID;
    }
    string getJOB_TITLE(){
        return job_title;
    }
    int getsalary(){
        return salary;
    }
      void cacl_Salary();
};
void Employee::cacl_Salary(){
    if (worked_hour <= 40){
         salary = worked_hour * pay;
    } else if (worked_hour > 40){
        int base_salary = 40 * pay; 
       int overtime = (worked_hour - 40) *(2*pay) ;
       salary = base_salary + overtime;
    }
}
void display(Employee emp[],int number_of_employee){
    
    for (int i = 0 ; i < number_of_employee ; i++){
      cout << "Employee No. "<< i + 1<< " :\n"<<endl;  
        cout << "Employee name : "<< emp[i].getname()<<endl;
          cout << "Employee ID : "<<emp[i].getID()<<endl;
           cout << "Employee job title : " << emp[i].getJOB_TITLE() <<endl; 
            cout << "Employee salary: " <<emp[i].getsalary() <<endl<<endl;
}
}
    

int main(){
    
    int number_of_employee;
    cout << "Enter number of employee: ";
    cin >> number_of_employee;

    Employee emp[number_of_employee];
    
     string name;
     string job_title;
     int worked_hour = 0;
     int ID= 0;
     int pay = 0;

    for (int i  = 0;i<number_of_employee;i++){
        cout << "Employee No. "<< i + 1<< " :\n"<<endl;
        cin.ignore();
        cout <<"Enter name of employee: ";
        getline(cin,name);
        cout << "Enter Employee ID: ";
        cin >> ID;
        cout << "Enter Employee job tile : ";
        cin >> job_title;
        cout << "Enter worked hour of emplyee : ";
        cin >> worked_hour;
        cout << "Enter pay per worked hour : ";
        cin >> pay;
       emp[i].setter(name,ID,job_title,worked_hour,pay);
       emp[i].cacl_Salary();
    }
    cout << "\n\n";
    display(emp,number_of_employee);
}