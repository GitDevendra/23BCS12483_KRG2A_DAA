// Insertion and deletion at beginning and at end for:
// 2. Doubly Linked List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, nullptr, head};
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        cout << value << " inserted at beginning." << endl;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << value << " inserted at end." << endl;
    }

    // Delete from beginning
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        cout << temp->data << " deleted from beginning." << endl;
        delete temp;
    }

    // Delete from end
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        if (temp->next == nullptr) { // Only one node
            cout << temp->data << " deleted from end." << endl;
            delete temp;
            head = nullptr;
            return;
        }
        while (temp->next != nullptr) temp = temp->next;
        cout << temp->data << " deleted from end." << endl;
        temp->prev->next = nullptr;
        delete temp;
    }

    // Display list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Driver code
int main() {
    DoublyLinkedList dll;

    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.display();

    dll.deleteAtBeginning();
    dll.display();

    dll.deleteAtEnd();
    dll.display();

    return 0;
}
