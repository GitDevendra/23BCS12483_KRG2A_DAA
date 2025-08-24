// Insertion and deletion at beginning and at end for:
// 2. Circular Linked List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
            head->next = head; // circular
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << value << " inserted at beginning." << endl;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << value << " inserted at end." << endl;
    }

    // Delete from beginning
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == head) { // Only one node
            cout << head->data << " deleted from beginning." << endl;
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* last = head;
        while (last->next != head) last = last->next;
        head = head->next;
        last->next = head;
        cout << temp->data << " deleted from beginning." << endl;
        delete temp;
    }

    // Delete from end
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == head) { // Only one node
            cout << head->data << " deleted from end." << endl;
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        cout << temp->data << " deleted from end." << endl;
        delete temp;
    }

    // Display list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

// Driver code
int main() {
    CircularLinkedList cll;

    cll.insertAtBeginning(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.display();

    cll.deleteAtBeginning();
    cll.display();

    cll.deleteAtEnd();
    cll.display();

    return 0;
}
