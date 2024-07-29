#include<iostream>
using namespace std;


class person{
    protected:

    string name;
    int age;
    string gender;

    public :
    person(string Name = "Ali", int Age = 15, string Gender = "Male") : name(Name),age (Age), gender(Gender) {}

   void setperson(){
    cout << "Enter name : ";
    getline(cin , name);
    cout << "Enter age: ";
    cin >>  age;
    cout << "Enter gender: ";
    getline(cin>>ws,gender);
   } 
    
};

class patient : public person{
    string disease;
   float admitted_time;
   string hospital_name;
   string its_doctor;

   public :
   
   patient (string Disease = "Cancer",string Hospital_name = "Hayatabad Medical Complex",float Admitted_time = 1.5 , string Doctor = "steve smith" ,string Name = "Ali", int Age = 15, string Gender = "Male") : disease(Disease),hospital_name(Hospital_name),admitted_time(Admitted_time),its_doctor(Doctor),person(Name,Age, Gender){}
   
   void setpatient (){
       cout << "\nEnter Patient Information \n";
      setperson();

      cout << "Enter Disease : ";
      getline(cin , disease);

      cout << "Enter Admitted time of patient(month) in  Hospital: ";
      cin >> admitted_time;

      cout << "Enter The name Patient's doctor : ";
      cin >> its_doctor;

   }

   void display (){
    cout << "\n\n         -------Patient Information-------\n";
    cout << "\t\t\t "<< hospital_name<<endl;
    cout << "Patient name: "<< name<<endl;
    cout << "Patient age : "<< age << endl;
    cout << "Patient gender : "<< gender<< endl;
    cout << "Patient Disease : " << disease << endl;
    cout << "Patient's Doctor : "<< its_doctor<< endl;
    cout << "Patient Admitted time in Hospital : "<< admitted_time<<endl;

   }

};
int main(){
    patient a1;
    a1.setpatient();
    a1.display();
}