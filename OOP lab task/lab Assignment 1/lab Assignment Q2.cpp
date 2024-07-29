#include<iostream>
using namespace std;

// class of food item
class FoodItem{
    // data member for detail 
    string name;
    float grams_of_protein;
    float grams_of_carbohydrates;
    float grams_of_fat;
    float calories;

public:

    // different constructor by argument  for diiferent prespect for initializing data member
    FoodItem() : name(""),grams_of_protein(0.0),grams_of_carbohydrates(0.0),grams_of_fat(0.0),calories(0.0) {}   
    FoodItem(string Name ) : name(Name),grams_of_protein(0.0),grams_of_carbohydrates(0.0),grams_of_fat(0.0),calories(0.0) { }
    FoodItem(string Name,int protein,int Carbohydrates,int Fat,int Calories) : name(Name),grams_of_protein(protein),grams_of_carbohydrates(Carbohydrates),grams_of_fat(Fat),calories(Calories) { }


    // prototype of friend function for granting friendship 
    friend float calculating_calories(const FoodItem& food);

    // prototype of friend function for granting friendship 
    friend void display(const FoodItem& item);

 // setters for setting values of different data member differently
    void set_name(string Name) {
         name = Name; 
    }
    void set_protein_grams(float protein_Grams) {
         grams_of_protein = protein_Grams; 
    }
    void set_carbo_grams(float carbohydrates_Grams) {
         grams_of_carbohydrates = carbohydrates_Grams;
    }
    void set_fat_grams(float fat_Grams) { 
        grams_of_fat = fat_Grams;
    }  
    void set_calories(float Calories) { 
        calories = Calories; 
    }

    // getters for returning each data member differenrly 
    string get_name() const {
         return name;
     }
    float get_protein_grams() const {
         return grams_of_protein;
    }
    float get_carbo_grams() const { 
        return grams_of_carbohydrates;
    }
    float get_fat_grams() const {
         return grams_of_fat;
    }
    float get_calories() const {
         return calories;
    }

};
 
 // defination of friend function
  float calculating_calories(const FoodItem& food){
    float  calorie;
   if (food.get_fat_grams() != 0){
    // calculating calories
    calorie =  (4 * food.get_protein_grams()) + (4 * food.get_carbo_grams()) +  (9 * food.get_fat_grams());

} else {
     
    // without including fats
    calorie =  (4 * food.get_protein_grams()) + (4 * food.get_carbo_grams()); 
}

    // returning calories
    return calorie; 
}

void display(const FoodItem& item){ //non member freind function for displaying data

        //  displaying all detail
     cout << "\nDetailed Item:" << endl;
     cout << "Name: " << item.get_name() << endl;
     cout << "Calories: " << item.get_calories() <<" kcal" << endl;  
     cout << "Protein: " << item.get_protein_grams() << " grams" << endl;
     cout << "Carbohydrate: " << item.get_carbo_grams() << " grams" << endl;
     if (item.get_fat_grams() != 0){
        cout << "Fat content: " << item.get_fat_grams() << " grams" << endl;
        }
 
}

    
int main() {

    // data member for detail
    string name;
    float   protein, carbs,fats;
    string choice;
    int Choice;
    int iteration;
    
     // starting loop until user say no
    do {
        
        // setting fats = 0 for each iterate
        fats = 0.0;
        // getting detail of book by user

        cout << "Enter the food item name (or exit to quit): ";
        getline(cin, choice);

        // if user wanna quit 
        if (choice == "exit" || choice == "quit") {
            break;
        }

        // making a object of  the name of itemby passing name as arguement in it
        FoodItem item(choice); 

    do{
        cout << "Enter protein in grams: ";
        cin >> protein;
        // it mean if input value is numeric loop will break 
        iteration = 0;

    // restriction to user for inputing invalid value
    // like if value is negative or non numeric
        if (cin.fail() || protein < 0) {

            cout << "Invalid input."<<endl;

     // built in function for clear input
            cin.clear();

    // built in function to skip any other character if remain in buffer
    // setting limit to 100 , if there are 100 char in buffer , it will skip them 
            cin.ignore(100, '\n');  
            iteration++; // for another iteration
            continue;
  }
    } while (iteration);

// calling member function to set protein
    item.set_protein_grams(protein);


    do{
        cout << "Enter carbohydrate content (grams): ";
        cin >> carbs;

        iteration = 0;

        if (cin.fail() || protein < 0) {

            cout << "Invalid input."<<endl;
            cin.clear();
            cin.ignore(100, '\n'); 
            iteration++;
            continue;

        }
    } while (iteration);

// calling member function to set cardo hydrates
    item.set_carbo_grams(carbs);


    do {
         // lets user user whether to include fats or not 
    cout << "Do you wanna add fat content as well ? (1 for yes & 0 for no): ";
    cin >> Choice;   

    } while (Choice != 1 && Choice != 0 );  


       if (Choice == 1){

    do {       
        cout << "Enter fat content (grams): ";
        cin >> fats;

        iteration = 0;

        if (cin.fail() || protein < 0) {

            cout << "Invalid input."<<endl;
            cin.clear();
            cin.ignore(100, '\n');  
            iteration++;
            continue;

        }
    } while (iteration);
  }

// calling member function to set fat
  item.set_fat_grams(fats);
      

        // calling friend function for to calculated calorie and return result
        int Calories = calculating_calories(item);

        // through setter initializing its value in object
        item.set_calories(Calories);
        cin.ignore();
        
        display(item);

         
    } while (1);


}
