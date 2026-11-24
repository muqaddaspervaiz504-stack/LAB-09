#include <iostream>
#include <string>
using namespace std;

template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
T findMax(T arr[], int n) {
    T maxValue = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

template <typename T>
int countValue(T arr[], int n, T value) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}

template <typename T>
int search(T arr[], int n, T value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {

    int numbers[] = {4, 9, 2, 9, 7};
    int n1 = 5;

    printArray(numbers, n1);
    cout << "Max: " << findMax(numbers, n1)
         << ", count of 9: "
         << countValue(numbers, n1, 9) << endl;

    double prices[] = {31.5, 28, 35.2};
    int n2 = 3;

    printArray(prices, n2);

    cout << "Max: " << findMax(prices, n2) << endl;
    string names[] = {"Ali", "Sara", "Zain", "Sara"};
    int n3 = 4;

    printArray(names, n3);
    cout << "Max: " << findMax(names, n3)
         << ", Sara found at index "
         << search(names, n3, string("Sara")) << endl;

    char letters[] = {'B', 'A', 'C', 'A', 'A'};
    int n4 = 5;

    printArray(letters, n4);
    cout << "Count of A: "
         << countValue(letters, n4, 'A')
         << ", D found at index "
         << search(letters, n4, 'D') << endl;

    return 0;
}
