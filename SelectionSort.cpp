#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void selectionSort(Node* head) {
    for (Node* i = head; i && i->next; i = i->next) {
        Node* min = i;
        for (Node* j = i->next; j; j = j->next)
            if (j->data < min->data) min = j;
        swap(i->data, min->data);
    }
}

void push(Node*& head, int data) {
    Node* newNode = new Node{data, head};
    head = newNode;
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

    selectionSort(head);
    print(head);
    return 0;
}
