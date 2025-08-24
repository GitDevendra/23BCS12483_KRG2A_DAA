#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    int top;
    int capacity;
    T* arr;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Check if stack is full
    bool isFull() {
        return (top == capacity - 1);
    }

    // Push operation
    void push(T value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack." << endl;
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }

    // Peek (Top element)
    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return T(); // Return default value
        }
        return arr[top];
    }

    // Return current size of stack
    int size() {
        return top + 1;
    }

    // Clear stack
    void clear() {
        top = -1;
        cout << "Stack cleared." << endl;
    }

    // Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack<int> s(5); // Stack of integers with size 5

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element: " << s.peek() << endl;
    cout << "Stack size: " << s.size() << endl;

    s.pop();
    s.display();

    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70); // Overflow
    s.display();

    cout << "Clearing stack..." << endl;
    s.clear();
    s.display();

    return 0;
}
