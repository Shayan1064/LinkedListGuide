#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void bubbleSort(Node* head) {
    bool swapped;
    do {
        swapped = false;
        for (Node* i = head; i && i->next; i = i->next) {
            if (i->data > i->next->data) {
                swap(i->data, i->next->data);
                swapped = true;
            }
        }
    } while (swapped);
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
    push(head, 10);
    push(head, 40);
    push(head, 30);
    push(head, 20);
    push(head, 50);

    bubbleSort(head);
    print(head);
    return 0;
}
