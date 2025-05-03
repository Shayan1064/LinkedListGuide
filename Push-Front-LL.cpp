#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data=value;
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
    void Push_Front(int value){
        Node* newnode=new Node(value);
        if (head==NULL)
        {
            head=tail=newnode;
        }else{
            newnode->next=head;
            head=newnode;
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
List sha;
sha.Push_Front(5);
sha.Push_Front(4);
sha.Push_Front(3);
sha.Push_Front(2);
sha.Push_Front(1);
sha.Display();
}