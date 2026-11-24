#include <iostream>
using namespace std;

class IntList {
private:
    int* data;
    int count;
    int capacity;

    void grow() {
        int oldCapacity = capacity;
        capacity = capacity * 2;

        int* newData = new int[capacity];
        for (int i = 0; i < count; i++) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        cout << "Resizing: " << oldCapacity
             << " -> " << capacity << endl;
    }

public:
    IntList() {
        capacity = 2;
        count = 0;
        data = new int[capacity];
    }

    ~IntList() {
        delete[] data;
        cout << "IntList memory freed" << endl;
    }

    void add(int value) {
        if (count == capacity) {
            grow();
        }
        data[count] = value;
        count++;
    }

    int get(int index) {
        if (index < 0 || index >= count) {
            cout << "Invalid index " << index << endl;
            return -1;
        }
        return data[index];
    }

    int size() {
        return count;
    }

    void print() {
        cout << "List (" << count << "/" << capacity << "): ";
        for (int i = 0; i < count; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    IntList list;

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);
    list.add(60);

    list.print();
    cout << "Item at 3: " << list.get(3) << endl;
    cout << "Item at 10: " << list.get(10) << endl;
    cout << "Size: " << list.size() << endl;

    return 0;
}
