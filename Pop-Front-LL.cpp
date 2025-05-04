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
   void Pop_Front(){
    if (head==NULL)
    {
        cout<<"LinkedList is Empty"<<endl;
    }else{
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
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
myList.Display();
}