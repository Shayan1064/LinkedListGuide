#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertionSort(Node*& head) {
    Node* sorted = nullptr;
    while (head) {
        Node* cur = head;
        head = head->next;
        if (!sorted || cur->data < sorted->data) {
            cur->next = sorted;
            sorted = cur;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->data < cur->data)
                temp = temp->next;
            cur->next = temp->next;
            temp->next = cur;
        }
    }
    head = sorted;
}

void push(Node*& head, int data) {
    head = new Node{data, head};
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = nullptr;
    push(head, 30);
    push(head, 10);
    push(head, 50);
    push(head, 20);
    push(head, 40);

    insertionSort(head);
    print(head);
    return 0;
}
