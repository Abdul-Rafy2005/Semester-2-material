#include <iostream>
#include <string>
using namespace std;

// class of related to detail of a Bank Account 
class BankAccount {

   // some data member for detail data of a account 
    int accountNumber;
    string accountHolder;
    double balance;
    // static for a reason to count total accounts
    static int total_accounts;

public:
    // constructor for initializing data member initially 
    BankAccount(string AccountHolder = "N/A") : accountHolder(AccountHolder), balance(0) {
        accountNumber = total_accounts; // assigning each account a new unique account number in sequence
    }
 
    // friend class . class BankManger is granting friend ship from class BankAccount
    friend class BankManager; 
    
    // static function for increament in tatol account count 
    static void No_of_Accounts(){
        total_accounts++;
    }

    // member function for doing calculation for deposting balance in account
    int deposit(const double amount) {

        if (amount > 0) { // condition for operating on only correct real 

            balance += amount; // adding in available balance
            return 1;

        } else {

             return 0;
        }
    }

   // member function for doing calculation for withdrawing balance
    int withdraw(const double amount) {
 
        if (amount <= 0) { // again condition for restricting user's wrong input 

            cout << "Invalid Amount." << endl;
            return 0;

        } else if (amount > balance){ // if amount is greater than original amount present in account

            cout << "Opteration Failed\nAmount exceeding the available balance in Account." << endl;            
        }

        balance -= amount; // withdrawing amount from available balance
        return 1;
    }

    // member function for returning available balance
    double getBalance() const {
        return balance;
    }

    // friend member function for transfer balance from one account to another
    void transferMoney(BankAccount& receiver_account, const double amount);
};

// assigning the static data member total account to 0
int BankAccount::total_accounts = 0;


 // definaion of friend function outside class
void BankAccount::transferMoney(BankAccount& receiver_account, const double amount) {

   // at first withdrawing amount perfectly
    if (withdraw(amount)) {

    // then deposting the amount to the reciever's account
        receiver_account.deposit(amount);
        cout << "Transferred Successfully." << endl;

    } else {

        cout << "Transfer failed." << endl;
    }
}

 // class of handling accounts
class BankManager {

    int number_of_Acc; // counting accounts
    BankAccount* accounts; // pointer  of type BookAccount
    

public:
     // constructor for initializing data initially
    BankManager() : number_of_Acc(0), accounts(nullptr) {}

    ~BankManager() { // destructor for deallocating space from heap

        delete[] accounts;
        cout << "Destructor Called."<<endl;

    }


    // member function for creating a new account
    void createBankAccount(const string& Name) {
        
        accounts->total_accounts++;

        //  making a temporary pointer of tpye bankaccount is assingning it a array of object
        // dynamically of size (number_of_Acc + 1)
        BankAccount* temporary = new BankAccount[number_of_Acc + 1];

        // assigning data to the temporary accounts array from actual accounts
        for (int i = 0; i < number_of_Acc; i++) {
            temporary[i] = accounts[i];
        }

        // assignig the data for the new account to the temporary accounts
        temporary[number_of_Acc] = BankAccount(Name);

        // deallocating the actual one accounts
        delete[] accounts;
        // assigning temporary accounts address to actual accounts
        accounts = temporary;
        // total counts increase by 1 due to new account
        number_of_Acc++;
    }



   // member function for delete account
    void deleteAccount(const int Acc_number) {
        
       accounts->total_accounts--;

        int i; //try for finding the account by account number
        for (i = 0; i < number_of_Acc; i++) {
               // if found
            if (Acc_number == accounts[i].accountNumber) {

             
            // total counts decreament by 1 due to deleting a account
                 number_of_Acc--; 

                //starting loop from here for assigning data from the next to account
                // to the previous one
                for (; i < number_of_Acc; i++) {
                    accounts[i] = accounts[i + 1];
                }

                break;
            }
        }

        //  making a temporary pointer of tpye bankaccount is assingning it a array of object
        // dynamically of size (number_of_Acc - 1)
        BankAccount* temporary = new BankAccount[number_of_Acc];

        // assigning data to the temporary accounts array from actual accounts
        for (i = 0; i < number_of_Acc; i++) {
            temporary[i] = accounts[i];
        }

        // deallocating the actual one accounts
        delete[] accounts;
        // assigning temporary accounts address to actual accounts        
        accounts = temporary;

    }


    // member function for finding account by account number by return that account 
    BankAccount* findBankAccount(const int Acc_number) {

        for (int j = 0; j < number_of_Acc; j++) { // searching/finding account by account number

            if (accounts[j].accountNumber == Acc_number) {
                return &accounts[j]; // if found then return by address 
            }

        }
        return nullptr; // if not , then  just returning null pointer
    }


    // member function for displaying all accounts
    void displayAllAccounts() {

        cout << "\nTotal Accounts : " << BankAccount::total_accounts <<endl <<endl;

        for (int k = 0; k < number_of_Acc; k++) {

            cout << "Account Holder : " << accounts[k].accountHolder << endl;
            cout << "Account Number : " << accounts[k].accountNumber << endl;
            cout << "Available Balance : " << accounts[k].balance <<endl << endl;

        }
    }
};

int main() {

    // creating a object of Bankmanager class
    BankManager managing;

    string Name; // some variable for  getting detail from user 
    int acc_number;
    double amount;
    int choice;

    do {
         // Menu CLI Interface
        cout << "\n\t\t-------Bank Management System-------" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Delete Account" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Withdraw Money" << endl;
        cout << "5. Display Accounts" << endl;
        cout << "6. Transfer Balance" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1: { // wanna create a new Account
                
                cin.ignore();
                // getting account holder name for creating name
                cout << "Enter account holder name: ";
                getline(cin,Name);
                
                // calling create account function & and passing name in it ; 
                managing.createBankAccount(Name);

                cout << "Account created successfully." << endl;
                break;
            }


            case 2: { // wanna delete account
                
                // asking for providing account number for delete that account
                cout << "Enter account number to delete: ";
                cin >> acc_number;

                 // calling function for delete account
                managing.deleteAccount(acc_number);

                cout << "Account deleted successfully!" << endl;
                break;
            }


            case 3: { // if wanna deposit money
                
                
                cout << "Enter account number to deposit money into: ";
                cin >> acc_number;
                

                cout << "Enter amount to deposit: ";
                cin >> amount;
               
                // making a pointer of type bankaccount & is assigning the address of the account
                // match with account number by calling find account function
                BankAccount* account = managing.findBankAccount(acc_number);

                if (account) { // if account found

                    if (account->deposit(amount)) { //   if suucessfully deposit

                        cout << "Withdrawal of Rs." << amount << " successful" << endl;
                        cout << "New balance: Rs." << account->getBalance() << endl;

                    } else { // if not

                        cout << "Deposit operation failed." << endl;
                    }

                } else { // if not found

                    cout << "Account not found." << endl;
                }
                break;
            }

            case 4: { // wanna withdraw money

                cout << "Enter account number to withdraw money from: ";
                cin >> acc_number;

                cout << "Enter amount to withdraw: ";
                cin >> amount;

                // making a pointer of type bankaccount & is assigning the address of the account
                // match with account number by calling find account function
                BankAccount* account = managing.findBankAccount(acc_number);

                if (account) { // if account found

                // withdrawing money by calling deposit function
                    if (account->withdraw(amount)) { //   if suucessfully withdraw

                        cout << "Withdrawal of Rs." << amount << " successful" << endl;
                        cout << "New balance: Rs." << account->getBalance() << endl;

                    } else { // if not

                        cout << "Withdrawal failed." << endl;
                    }

                } else { // if account not found

                    cout << "Account not found." << endl;
                }
                break;
            }

            case 5: // wanna display detail

                // provoking function display for displaying all accounts detail 
                managing.displayAllAccounts();
                break;

            case 6: { // wanna treasfer money

                int sender, receiver;

                cout << "Enter receiver's account number: ";
                cin >> receiver;

                cout << "Enter sender's account number: ";
                cin >> sender;

                cout << "Enter amount to transfer: ";
                cin >> amount;

                // making two pointers of type bankaccount & is assigning the addresses of the accounts
                // match with account numbers by calling find account function
                BankAccount* account1 = managing.findBankAccount(sender);
                BankAccount* account2 = managing.findBankAccount(receiver);

                if (account1 != nullptr && account2 != nullptr) { // if both account found

                    account1->transferMoney(*account2, amount); // provoking transfer money function by account1 object

                } else { // if any of  account not found

                    cout << "Transfer failed. Account Not Found." << endl;

                }
                break;
            }
            case 7: // wanna exit program

                cout << "Exited" << endl;
                return 0;

            default: 
                cout << "Invalid choice." << endl;
        }
    } while (1);
    return 0;
}
