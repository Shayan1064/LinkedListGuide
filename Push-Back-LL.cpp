#include <iostream>
using namespace std;

class Node {
    public:

    int data;
    Node* next;

    Node(int value){
        data =value;
        next=NULL;
    }
};

class List{
    Node* head;
    Node* tail;
    public:
    List(){
        head=tail=NULL;
    }
    void Push_Back(int value){
        Node* newnode=new Node(value);
        if (head==NULL)
        {
            head=tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    void Display(){
        Node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        
    }
};
int main(){
List myList;
myList.Push_Back(1);
myList.Push_Back(2);
myList.Push_Back(3);
myList.Push_Back(4);
myList.Push_Back(5);
myList.Display();
}