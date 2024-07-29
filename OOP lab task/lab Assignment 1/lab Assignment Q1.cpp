#include<iostream>
#include<string>
using namespace std;

// class of name book 
class Book {
    // data member for contact
    string title;
    string author;
    string genre;
    // data member for availability of book in your collection 
    int availability_status;

public:
// default parametrize constructor to initialize data member
    Book(string Title = "", string Author = "" , string Genre = "", int  Availability_status = 0) : title(Title), author(Author), genre(Genre), availability_status(Availability_status) {}

   // getters to return each data member
    string gettitle() { return title; }
    string getauthor() { return author; }
    string getgenre() { return genre; }
    int getavailabilityStatus() { return availability_status; }
};

// class of name library
class Library {
    // data member for counting no. of books in your collection
    int count_book;
    // double pointer data member of type class book to make a 2d array dynamically  
    // to store book information
    Book** book;

public:
   // default constructor &  allocating space from heap to pointer book 
   // for making 2d array 
    Library() : count_book(0) {
        book = new Book*[1];
    }

    // destructor for deallocating space occupied by 2d array
    ~Library() {
        for (int i = 0; i < count_book; ++i) {
            delete book[i];
        }
        delete[] book;
        cout << "Destructor is called." << endl;
    }

    // member function for adding new book to collection
    void add_book(const string& Title, const string& Author, const string& Genre, const int& Availability_status) {
       
        // resizing array by increase 1  by make another temporary array
        Book** temporary = new Book*[count_book + 1];
        
        // assigning the old data to temporary array 
        for (int i = 0; i < count_book; ++i) {
            temporary[i] = book[i];
        }

        // now assigning the new data to temporary array
        temporary[count_book] = new Book(Title, Author, Genre, Availability_status);
        // ADD a new book to collection
        count_book++;
        // deallocating old array & assigning it the data of upadeted array
        delete[] book;
        book = temporary;
        
    }

    // member function for displaying book detail by searching it by genre  
    void displaybooksByGenre(const string& genre) {

       // for checking whether book is present in our collection or not
        int count = 0;

        cout << "Available books in " << genre << ":" << endl;

        // checking in our collection
        for (int i = 0; i < count_book; ++i) {
            // if any book's genre is same as the one input by user 
            // displaying its information

            if (book[i]->getgenre() == genre && book[i]->getavailabilityStatus()) {
                cout << "Title: " << book[i]->gettitle() << endl;
                cout << "Author: " << book[i]->getauthor() << endl;
                count++;
            }
        }
         // if no book found
        if (count == 0) {
            cout << "No available books in this genre." << endl;
        }
    }
};

int main() {

     // making a object of Library
    Library lib;

    cout << "\n\t\t -------Library Management------- " << endl;


   // data member for detail
    string title, author, genre;
    int availability_status;
    char choice;

   // starting loop until user say no
    do {

        // getting detail of book by user
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter book author: ";
        getline(cin, author);
        cout << "Enter book genre: ";
        getline(cin, genre);
        cout << "Is the book available? (1 for Yes, 0 for No): ";
        cin >> availability_status;
        cout << "Book added successfully. \n";

        // sending the detail to add book dunction to add it in your collection
        lib.add_book(title, author, genre, availability_status);

         // loop until user do not input correct value 
        do {
            
            cout << "Do you want to add another book (y/n)? ";
            cin >> choice;
            cin.ignore(); 
        } while (choice != 'n' && choice != 'N' && choice != 'Y' && choice != 'y');

    } while (choice != 'N' && choice != 'n');

    // loop until user do not input correct value 
    do { 

        string Genre;
        // asking for genre to search book
        cout << "Enter the genre to display available books: ";
        getline(cin, Genre);
        
        // sending genre to function display bookby genre
        lib.displaybooksByGenre(Genre);

    // loop until user do not input correct value 
        do {

            cout << "Do you want to check by another genre (y/n)? ";
            cin >> choice;
            cin.ignore(); // skiping new line character
            
        } while (choice != 'n' && choice != 'N' && choice != 'Y' && choice != 'y');

    } while (choice != 'N' && choice != 'n');

    return 0;
}
