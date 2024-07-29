#include<iostream>
using namespace std;
class population{
    private: 
    int number_of_birth;
    int number_of_death;
    int population_per_year;
    float birthrate,deathrate;
    public:
    // default constructer
    population(){
     number_of_birth = 0;
     number_of_death = 0;
     population_per_year = 0;
     birthrate = 0.0;
     deathrate = 0.0;
    }

    void set_birthrate(int birth){
        number_of_birth = birth;
    }
    void set_deathrate(int death){
        number_of_death = death;
    }
    void set_population(int Population){
        population_per_year = Population;
    }

    float  get_birthrate(){
         birthrate = float (number_of_birth)/population_per_year;
         return birthrate;
    }

    float  get_deathrate(){
         deathrate = float (number_of_death)/population_per_year;
         return deathrate;
    }

};
int main(){
    int number_of_birth;
    int number_of_death;
    int population_per_year;

   do { cout << "Enter the population of this year: ";
    cin >> population_per_year;
   } while (population_per_year < 1);
    
     do { cout << "Enter number of birth of this year: ";
     cin >> number_of_birth;
    } while (number_of_birth <0);

    do { cout << "Enter number of death of this year: ";
     cin >> number_of_death;
     } while (number_of_death <0); 

       population test;
      test.set_birthrate(number_of_birth);
      test.set_deathrate(number_of_death);
      test.set_population(population_per_year);
   
      cout << "birth rate of this  year is : "<< test.get_birthrate()<<endl;
      cout << "death rate of this  year is : "<< test.get_deathrate()<<endl;
}