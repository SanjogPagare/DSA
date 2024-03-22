#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        cout<<"i am a defoult ctor"<<endl;
       this->next = NULL;
    }

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertAtHead(Node* &head,Node* tail,int data){ // always pass by reference
    if(head == NULL){
        //empty linked list
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        //linked list is not empty
    // create a new node
    Node* newNode = new Node(data);
    // attach new node to head node
    newNode->next= head;
    // update head
    head = newNode;
    }
}
void print(Node* head){
    Node* temp= head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<endl;
}

int main(){
    // Node obj1;
    Node* first= new Node(10);
    Node* second= new Node(20);
    Node* third= new Node(30);
    first->next=second;
    second->next=third;
    Node* head= first;
    Node* tail = third;
    print(head);
    insertAtHead(head,tail,500);
    print(head);
}
