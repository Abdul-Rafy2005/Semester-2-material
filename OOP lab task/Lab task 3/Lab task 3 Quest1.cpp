#include<iostream>
#include<string>
using namespace std;
// Declaring the a Structure
struct MovieData{
    // Structure member
    string title;
    string Director;
    int Year_Released;
};
// declaring function to take input and second one for showing output
MovieData createMovieData();
void displayMovieData(MovieData*);
int main(){
    // creating two variable of structure
     MovieData Movie1,Movie2;
     // calling function and assiging the return value to struct varaible
     Movie1 = createMovieData();
    displayMovieData(&Movie1);
     Movie2 = createMovieData();
     displayMovieData(&Movie2);
    return 0;
}
// function for taking input an returning structure
MovieData createMovieData(){
      MovieData movie;
      cout << "Enter the title of movie: ";
      getline(cin,movie.title);
      cout << "Enter the Directer name: ";
      getline(cin,movie.Director);
      cout << "Enter the release year: ";
      cin >> movie.Year_Released;
      cin.ignore();
      return movie;
}
// function for displaying output
void displayMovieData(MovieData *movie){

    cout << "Title: "<<movie->title<<endl;
    cout << "Director: "<<movie->Director<<endl;
    cout<<"Release Year: "<<movie->Year_Released<<"\n\n";


}