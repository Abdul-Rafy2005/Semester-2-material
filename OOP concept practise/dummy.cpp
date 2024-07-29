#include<iostream>
using namespace std;
class saving_account;
class BankAccount_p230560{
    float  *balance;
    int numberofdeposits;
    int numberofwithdraws;
    float AnnualintersetRate;
    int MonthlyServiceCharges;

    public:
    BankAccount_p230560(float Balance = 0.0, float annualintersetRate = 0.0 )  {
        balance = new float(Balance);
        AnnualintersetRate = annualintersetRate;
        MonthlyServiceCharges = 10;

    }

    virtual ~BankAccount_p230560(){
        delete balance;
    }


    friend  class saving_account; 



    virtual void deposits(float amount) {
        *balance += amount;
        cout << amount << "$ deposits successfully.\n";
        cout << "Current balance: " << *balance <<endl;
    }

    virtual void withdraws(float amount){
         *balance -= amount;
        cout << amount << "$ Withdraws successfully.\n";
        cout << "Current balance: " << *balance <<endl;

    }

    virtual void calcInt(){

        float monthly_interset_rate = (AnnualintersetRate/12.0);
        float monthly_interset  = *balance * monthly_interset_rate;
        *balance += monthly_interset;

    }

    virtual void monthlyProc(){

        *balance -= MonthlyServiceCharges;
        calcInt();
        numberofdeposits = 0;
        numberofwithdraws = 0;
        MonthlyServiceCharges = 0;

    }

    virtual void operator=(const BankAccount_p230560& obj2) = 0;


};


class saving_account : public BankAccount_p230560{


    bool check;
    public:
      saving_account(bool Check, float balance , float interset ) :BankAccount_p230560(balance,interset),check(Check) {}
       virtual ~saving_account(){}
  
     void withdraws(float amount ){

        if (*balance <= 25) {
              cout << "Your account is inactive. \n";
              cout << "withdraw not allowed\n";
        } else{

            BankAccount_p230560::withdraws(amount);
            if (*balance <= 25) check = false;
            numberofwithdraws++;

        }
     }

     void deposits(float amount){
        if ((*balance + amount) > 25) {

            BankAccount_p230560::deposits(amount);
            numberofdeposits++;

     }    else {
          cout << "Your account is inactive. \n";
          cout << "low balance , deposits more money. \n";
     }
}


    
       void monthlyProc(){

           if (numberofwithdraws > 4){
            MonthlyServiceCharges++;
           }

           BankAccount_p230560::monthlyProc();
           if (*balance <= 25){
              check = false;
       }
}

    
    void operator=(const BankAccount_p230560& obj2){

            balance = new float;
            *balance = *obj2.balance;

            numberofdeposits = obj2.numberofdeposits;
            numberofwithdraws = obj2.numberofwithdraws;
            MonthlyServiceCharges = obj2.MonthlyServiceCharges;
            AnnualintersetRate = obj2.AnnualintersetRate; 
            if (*balance <= 25){
                check = false;

            } else {
                check = true;
            }
    }


};


int main(){


     cout << "\t\tWelcome to bank account service" << endl;


       
     BankAccount_p230560 *array[2];
     array[0] = new saving_account(true,100.0,0.5);
     array[1] = new saving_account(true,50.0,0.5);

     array[0]->withdraws(80);
     array[0] = array[1]; // asssignment operator
     array[0]->withdraws(5);   
     array[0]->monthlyProc();
     array[0]->deposits(10);

      delete array[0];
      delete array[1];
}
