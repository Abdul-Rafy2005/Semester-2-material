#include <iostream>
using namespace std;
int main() {
    const int rows = 3;
    const int cols = 4;

    char myArray[4][4] = {
        {'Q', 'W', 'E', 'R'},
        {'T', 'Y', 'U', 'I'},
        {'O', 'P', 'A', 'S'},
        {'D', 'F', 'G', 'H'}
    };


    char (*ptr)[cols] = myArray;

    cout << "Reversed 2D array:" << endl;
    for (int i = rows; i >= 0; --i) {
        for (int j = cols - 1; j >= 0; --j) {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}