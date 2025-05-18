#include <iostream>

// Definition of the Node structure
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node
    Node(int value) : data(value), next(nullptr) {}
};

// Definition of the LinkedList class
class LinkedList {
private:
    Node* head;     // Pointer to the first node of the list

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value); // Create a new node
        newNode->next = head;           // Make the new node point to the current head
        head = newNode;                 // Update the head to the new node
        std::cout << "Inserted " << value << " at the beginning." << std::endl;
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value); // Create a new node
        if (head == nullptr) {          // If the list is empty
            head = newNode;             // Make the new node the head
        } else {
            Node* current = head;       // Start from the head
            while (current->next != nullptr) { // Traverse to the last node
                current = current->next;
            }
            current->next = newNode;    // Make the last node point to the new node
        }
        std::cout << "Inserted " << value << " at the end." << std::endl;
    }

    // Function to display the elements of the linked list
    void display() const {
        Node* current = head;       // Start from the head
        std::cout << "Linked List: ";
        while (current != nullptr) { // Traverse the list
            std::cout << current->data << " -> "; // Print the data
            current = current->next;             // Move to the next node
        }
        std::cout << "nullptr" << std::endl;   // Mark the end of the list
    }

    // Function to delete a node with a specific value
    void deleteNode(int value) {
        if (head == nullptr) {          // If the list is empty
            std::cout << "List is empty. Cannot delete." << std::endl;
            return;
        }

        if (head->data == value) {      // If the value is in the head node
            Node* temp = head;
            head = head->next;
            delete temp;
            std::cout << "Deleted node with value " << value << " (head)." << std::endl;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {      // If the value is not found
            std::cout << "Node with value " << value << " not found." << std::endl;
            return;
        }

        previous->next = current->next; // Remove the current node from the list
        delete current;                 // Free the memory of the current node
        std::cout << "Deleted node with value " << value << "." << std::endl;
    }

    // Destructor to free the memory of all nodes in the list
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr; // Reset head after deleting all nodes
        std::cout << "Linked List destroyed." << std::endl;
    }
};

// Example usage of the LinkedList
int main() {
    LinkedList myList;
    myList.insertAtEnd(10);
    myList.insertAtBeginning(5);
    myList.insertAtEnd(20);
    myList.display(); // Output: Linked List: 5 -> 10 -> 20 -> nullptr
    myList.deleteNode(10);
    myList.display(); // Output: Linked List: 5 -> 20 -> nullptr
    return 0;
}