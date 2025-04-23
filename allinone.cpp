#include <iostream>
#include <vector>
#include <algorithm>

// 1. Array Operations: Searching and Sorting

// Linear Search: Finds the index of a target element in an array.
int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Binary Search: Efficiently finds the index of a target element in a *sorted* array.
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevent potential overflow
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Bubble Sort: A simple sorting algorithm (not very efficient for large datasets).
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 2. Linked List Operations: Insertion and Traversal

// Node structure for a singly linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert a new node at the beginning of the linked list.
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node(newData);
    newNode->next = head;
    head = newNode;
}

// Traverse and print the elements of the linked list.
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// 3. Stack Operations: Push and Pop

#include <stack>

// Demonstrate stack push and pop operations.
void stackOperations() {
    std::stack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top element of the stack: " << myStack.top() << std::endl;
    myStack.pop();
    std::cout << "Top element after pop: " << myStack.top() << std::endl;
    std::cout << "Size of the stack: " << myStack.size() << std::endl;
}

// 4. Queue Operations: Enqueue and Dequeue

#include <queue>

// Demonstrate queue enqueue and dequeue operations.
void queueOperations() {
    std::queue<std::string> myQueue;
    myQueue.push("Alice");
    myQueue.push("Bob");
    myQueue.push("Charlie");

    std::cout << "Front element of the queue: " << myQueue.front() << std::endl;
    myQueue.pop();
    std::cout << "Front element after pop: " << myQueue.front() << std::endl;
    std::cout << "Size of the queue: " << myQueue.size() << std::endl;
}

int main() {
    std::cout << "--- Array Operations ---" << std::endl;
    std::vector<int> numbers = {5, 2, 8, 1, 9};
    std::cout << "Original array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int searchElement = 8;
    int linearSearchResult = linearSearch(numbers, searchElement);
    if (linearSearchResult != -1) {
        std::cout << searchElement << " found at index: " << linearSearchResult << " (Linear Search)" << std::endl;
    } else {
        std::cout << searchElement << " not found (Linear Search)" << std::endl;
    }

    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end()); // Sort for binary search
    int binarySearchResult = binarySearch(sortedNumbers, searchElement);
    if (binarySearchResult != -1) {
        std::cout << searchElement << " found at index: " << binarySearchResult << " (Binary Search)" << std::endl;
    } else {
        std::cout << searchElement << " not found (Binary Search)" << std::endl;
    }

    std::vector<int> unsortedNumbers = {3, 1, 4, 1, 5, 9, 2, 6};
    std::cout << "Unsorted array for Bubble Sort: ";
    for (int num : unsortedNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    bubbleSort(unsortedNumbers);
    std::cout << "Sorted array (Bubble Sort): ";
    for (int num : unsortedNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "\n--- Linked List Operations ---" << std::endl;
    Node* head = nullptr;
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 15);
    std::cout << "Linked list: ";
    printLinkedList(head);

    // Clean up linked list memory (important to avoid memory leaks)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    std::cout << "\n--- Stack Operations ---" << std::endl;
    stackOperations();

    std::cout << "\n--- Queue Operations ---" << std::endl;
    queueOperations();

    return 0;
}