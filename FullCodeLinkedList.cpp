#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void pushfront(int value) {
        Node* newnode = new Node(value);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    void pushback(int value) {
        Node* newnode = new Node(value);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void popFront() {
        if (head == NULL) {
            cout << "LinkedList is Empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void Popback() {
        if (head == NULL) {
            cout << "LinkedList is Empty" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void Display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    List myList;
    myList.pushfront(5);
    myList.pushfront(4);
    myList.pushfront(3);
    myList.pushfront(2);
    myList.pushfront(1);
    myList.pushback(6);
    myList.pushback(7);
    myList.pushback(8);
    myList.pushback(9);
    myList.pushback(10);

    myList.Display();

    myList.popFront();
    myList.popFront();
    myList.Popback();
    myList.Popback();
    myList.Popback();

    myList.Display();

    return 0;
}
