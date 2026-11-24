#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack {
private:
    T* items;
    int capacity;
    int top;

public:
    Stack(int cap) {
        capacity = cap;
        top = 0;
        items = new T[capacity];
    }

    ~Stack() {
        delete[] items;
    }
    void push(T value) {
        if (top == capacity) {
            cout << "Stack is full, cannot push "
                 << value << endl;
        }
        else {
            items[top] = value;
            top++;
        }
    }

    T pop() {
        if (top == 0) {
            cout << "Stack is empty" << endl;
            return T();
        }

        top--;
        return items[top];
    }
    T peek() {
        if (top == 0) {
            cout << "Stack is empty" << endl;
            return T();
        }

        return items[top - 1];
    }
    bool isEmpty() {
        return top == 0;
    }
    bool isFull() {
        return top == capacity;
    }
    int size() {
        return top;
    }
};

int main() {

    Stack<int> numbers(3);
    numbers.push(10);
    numbers.push(20);
    numbers.push(30);
    numbers.push(40);
    cout << "\nPopping: ";
    while (!numbers.isEmpty()) {
        cout << numbers.pop() << " ";
    }
    cout << endl;

    Stack<char> letters(6);
    string word = "LAHORE";
    for (int i = 0; i < word.length(); i++) {
        letters.push(word[i]);
    }

    cout << "LAHORE reversed: ";
    while (!letters.isEmpty()) {
        cout << letters.pop();
    }

    cout << endl;

    Stack<string> history(3);
    history.push("google.com");
    history.push("github.com");
    history.push("gutech.edu.pk");

    cout << "Current page: "
         << history.peek() << endl;
    history.pop();
    cout << "After Back: "
         << history.peek() << endl;

    return 0;
}
