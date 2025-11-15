#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
public:
    Node* top;
    int size;

    Stack() {
        top = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int val) {
        Node* newnode = new Node(val);
        newnode->next = top;
        top = newnode;
        size++;
        cout << val << " pushed into stack\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty, cannot pop.\n";
            return;
        }
        Node* temp = top;
        cout << "Popped: " << top->data << "\n";
        top = top->next;
        delete temp;
        size--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    int getSize() {
        return size;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout << "Top element: " << st.peek() << "\n";

    st.pop();
    st.display();

    cout << "Current stack size: " << st.getSize() << "\n";

    return 0;
}