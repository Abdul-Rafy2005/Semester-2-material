#include<iostream>
#include<string>
using namespace std;

class Favourite_Songs{
    int size;
    string *pointer;

public:
    Favourite_Songs() : size(0), pointer(nullptr) {}

    // Copy constructor
    Favourite_Songs(const Favourite_Songs& object) : size(object.size), pointer(nullptr) {
        if (object.pointer != nullptr) {
            pointer = new string[size];
            for (int i = 0; i < size; i++) {
                pointer[i] = object.pointer[i];
            }
        }
    }

    // Destructor
    ~Favourite_Songs() {
        delete[] pointer;
        cout << "Destructor called." << endl;
    }

    // member function prototype
    void addSong(string song);
    void deleteSong(string song);
    void modifySong(string song);
    void printingSongs();
    void createBackup(const Favourite_Songs& other);
};

// member function for adding songs
void Favourite_Songs::addSong(string song){

    string *pointer2 = new string[size + 1];
    // copying from one to another
    for (int i = 0; i < size; i++) {
        pointer2[i] = pointer[i];
    }

    pointer2[size] = song; 
    delete[] pointer;
    pointer = pointer2;
    size++;
}

void Favourite_Songs::deleteSong(string song){

// finding required song index and then replacing it by its next on index
    int i = 0;
    for (; i < size; i++) {
        if (song == pointer[i]) {   
            for (; i < size - 1; i++) {
                pointer[i] = pointer[i + 1];
            }
            break;
        }
    }


    if (i == size) {
        cout << "Song Not Found." << endl;
        return;
    }

    size--;

    string* pointer3 = new string[size];
    // new array of size less than one by original
    for (int j = 0; j < size; j++) {
        pointer3[j] = pointer[j];
    }


    delete[] pointer;
    pointer = pointer3;
}


void Favourite_Songs::modifySong(string song){
    
    int i;
    for (i = 0; i < size; i++) {
        if (song == pointer[i]) {
            cout << "Enter new song: ";
            cin >> pointer[i];
            break;
        }
    }


    if (i == size)  
        cout << "Song Not Found." << endl;
}

void Favourite_Songs::printingSongs(){

    cout << "\nYour Song Playlist:\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << pointer[i] << endl;
    }

}


void Favourite_Songs::createBackup(const Favourite_Songs& other) {

    delete[] pointer; // deleting if exists
    size = other.size;

    if (other.pointer != nullptr) {

        pointer = new string[size];
        
        for (int i = 0; i < size; i++) {
            pointer[i] = other.pointer[i];
        }
        
    } else {
        pointer = nullptr;
    }
}


int main(){

    Favourite_Songs playlist;
    Favourite_Songs backup;

    int choice;
    string song;

    do {
        cout << "\n   Top Menu    " << endl;
        cout << "1. Add a new song" << endl;
        cout << "2. Delete a song" << endl;
        cout << "3. Update a song" << endl;
        cout << "4. Print songs" << endl;
        cout << "5. Create backup of the songs" << endl;
        cout << "6. Print Backup songs" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            
            case 1:
                cout << "Enter the name of the song to add: ";
                cin >> song;
                playlist.addSong(song);
                cout << "Added successfully." << endl;
                break;

            case 2:
                cout << "Enter the name of the song to delete: ";
                cin >> song;
                playlist.deleteSong(song);
                cout << "Deleted successfully." << endl;
                break;

            case 3:
                cout << "Enter the name of the song to update: ";
                cin >> song;
                playlist.modifySong(song);
                cout << "Modified successfully." << endl;
                break;

            case 4:
                playlist.printingSongs();
                break;

            case 5:
                backup.createBackup(playlist);
                cout << "Backup created successfully." << endl;
                break;
                   
            case 6:
                backup.printingSongs();
                break;   

            case 7:
                cout << "Exited." << endl;
                
                break;   

            default:
                cout << "Invalid choice. Enter a valid option." << endl;
        }
    } while (choice != 7);
     cout.flush();

    return 0;
}
