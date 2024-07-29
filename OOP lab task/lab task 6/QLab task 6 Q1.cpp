#include<iostream>
using namespace std;
class store{
    private :
    string name;
    int id;
    int price;
    int quantity;

    public:
    store(){
        id = 0;
        price = 0;
        quantity = 0;
        name = "Unknown";
    }

    store(string name,int id,int price, int quantity){
       this->name = name;
       this->id = id;
       this->price = price;
       this->quantity = quantity; 
    }

    string getname(){
        return name;
    }
    int getID(){
        return id;
    }
    int getPRICE(){
        return price;
    }
    int getQUANTITY(){
        return quantity;
    }
    
    void setPrice(int price) {
        this->price = price;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }
 
    void displayDetails() {
        cout << "\nID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }
   
    ~store(){
        cout << "Object destory. "<<endl;
    }
};

    
    void display_Items(store items[],int number_of_item){
      system("cls"); 
    for (int i = 0 ; i < number_of_item ; i++){
      cout << "\nItem No. "<< i + 1<< " :\n"<<endl;  
        cout << "item name : "<< items[i].getname()<<endl;
          cout << "Item ID : "<<items[i].getID()<<endl;
           cout << "Item price : " << items[i].getPRICE() <<endl; 
            cout << "Item qunatity: " <<items[i].getQUANTITY() <<endl<<endl;
       } 
    }

    void update_Item_Details(store items[]){
         system("cls"); 
          int option = 0;
          int item_number = 0;
          int updateprice,updatequantity;
          cout << "Enter Item number: ";
          cin >> item_number;

          cout <<"\n1.Wanna update price\n2.OR Quantity: ";
          cin >> option;

        if (option == 1){

            cout << "Enter Updated price: ";
            cin >> updateprice;
            items[item_number - 1].setPrice(updateprice);
            cout << "Updated....";

        } else if (option == 2){

           cout << "Enter Updated quantity: ";
            cin >> updatequantity;
            items[item_number - 11].setQuantity(updatequantity); 
           cout << "Updated....";
        }
    }
    void search_Item_By_Id(store items[],int number_of_item){
         system("cls"); 
         int ID;
         cout << "Enter the id : ";
         cin >> ID;
        int i,count;
        count = 0;
        for (i = 0 ; i < number_of_item ; i++){
            if (ID == items[i].getID()){
                items[i].displayDetails();
                count++;
                break;
                
            } 
        }
        if (count == 0) cout << "Not Found. \n\n";
    }


int main(){

  int number_of_item;
  cout << "Enter number of items you want: ";
  cin >> number_of_item;
  store items[number_of_item];

    string name;
    int id = 0;
    int price = 0;
    int quantity = 0;

  for (int i  = 0;i<number_of_item;i++){
        cout << "Item No. "<< i + 1<< " :\n"<<endl;
        cin.ignore();
        cout <<"Enter Item name : ";
        getline(cin,name);
        cout << "Enter item ID : ";
        cin >> id;
        cout << "Enter item price : ";
        cin >> price;
        cout << "Enter item quantity : ";
        cin >> quantity;
    items[i] = store(name,id,price,quantity);
    }
    cout << "\n\n";
    int option;
    do {
         
        cout << "Menu:" << endl;
        cout << "1. Display Items" << endl;
        cout << "2. Update item details" << endl;
        cout << "3. Search for items by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                display_Items(items,number_of_item);
                break;
            case 2:
                update_Item_Details(items);
                break;
            case 3:
                search_Item_By_Id(items,number_of_item);
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Invalid choice. " << endl;
        }
    } while (option != 4);
}