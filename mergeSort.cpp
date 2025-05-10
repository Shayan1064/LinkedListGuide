#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data < b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

void split(Node* source, Node** front, Node** back) {
    Node *slow = source, *fast = source->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

void mergeSort(Node*& head) {
    if (!head || !head->next) return;
    Node *a, *b;
    split(head, &a, &b);
    mergeSort(a);
    mergeSort(b);
    head = merge(a, b);
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
    push(head, 50);
    push(head, 20);
    push(head, 40);
    push(head, 10);
    push(head, 30);

    mergeSort(head);
    print(head);
    return 0;
}
