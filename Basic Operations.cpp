#include <iostream>
using namespace std;

// Function to display the array elements
void display(int arr[], int size) {
    cout << "Array Elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// imp: Function to insert an element at  
void insert(int arr[], int &size, int element, int position, int capacity) {
    if (size >= capacity) {
        cout << "Array is full, cannot insert element." << endl;
        return;
    }
    
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
}

 
void remove(int arr[], int &size, int position) {
    if (size == 0) {
        cout << "Array is empty, cannot delete element." << endl;
        return;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

//  dekh: Function to search for an element in the array
int search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int main() {
    int capacity = 10; // Maximum capacity of array
    int arr[capacity] = {10, 20, 30, 40, 50}; 
    int size = 5; // Current size of the array

    display(arr, size);
    
    // Inserting an element
    insert(arr, size, 25, 2, capacity);
    cout << "After Insertion: ";
    display(arr, size);

    // Deleting an element
    remove(arr, size, 3);
    cout << "After Deletion: ";
    display(arr, size);

    // note: Searching for an element
    int key = 30;
    int pos = search(arr, size, key);
    if (pos != -1)
        cout << "Element " << key << " found at index " << pos << endl;
    else
        cout << "Element " << key << " not found" << endl;

    return 0;
}
