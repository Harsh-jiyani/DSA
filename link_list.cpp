#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the end
    void insert(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout << "Linked List: ";
    list.display();

    return 0;
}
