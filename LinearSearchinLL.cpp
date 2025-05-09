#include <iostream>
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

// Function for linear search
bool linearSearch(Node* head, int key) {
    int index = 0;
    while (head) {
        if (head->data == key) {
            cout << "Element " << key << " found at index " << index << " (Linear Search)\n";
            return true;
        }
        head = head->next;
        index++;
    }
    cout << "Element " << key << " not found (Linear Search)\n";
    return false;
}

// Main function
int main() {
    Node* head = nullptr;

    // Insert sample values
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 50);

    display(head);

    // Perform linear searches
    linearSearch(head, 30);
    linearSearch(head, 25);

    return 0;
}
