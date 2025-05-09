#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a node at the end
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void display(Node* head) {
    cout << "Linked List: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Binary search in linked list by converting to sorted array
bool binarySearch(Node* head, int key) {
    vector<int> arr;

    // Convert linked list to array
    while (head) {
        arr.push_back(head->data);
        head = head->next;
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    // Perform binary search
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            cout << "Element " << key << " found at sorted index " << mid << " (Binary Search)\n";
            return true;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << "Element " << key << " not found (Binary Search)\n";
    return false;
}

// Main function
int main() {
    Node* head = nullptr;

    // Insert sample values
    insertEnd(head, 40);
    insertEnd(head, 10);
    insertEnd(head, 50);
    insertEnd(head, 20);
    insertEnd(head, 30);

    display(head);

    // Perform binary search
    binarySearch(head, 20);
    binarySearch(head, 60);

    return 0;
}
