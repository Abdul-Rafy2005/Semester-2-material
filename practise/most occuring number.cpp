#include <iostream>

int most_occuring_number(int arr[], int size) {
    int max_num = arr[0];
    int max_count = 1;

    // Find the most occurring number in the array
    for (int i = 0; i < size; ++i) {
        int current_num = arr[i];
        int current_count = 0;

        // Count occurrences of the current number
        for (int j = 0; j < size; ++j) {
            if (arr[j] == current_num) {
                current_count++;
            }
        }

        // Update max_num if necessary
        if (current_count > max_count) {
            max_num = current_num;
            max_count = current_count;
        }
    }

    return max_num;
}

int main() {
    int arr[] = {2, 3, 4, 2, 6, 4, 1, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = most_occuring_number(arr, size);
    std::cout << "Most occurring number: " << result << std::endl;

    return 0;
}
