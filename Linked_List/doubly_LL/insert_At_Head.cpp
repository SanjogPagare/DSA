#include<iostream>
using namespace std;

class Node{

public:
    int data;
    Node* prev;
    Node* next;


    Node(){
        this->next=NULL;
        this->prev=NULL;
    }

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

void insertAtHead(Node* &head,Node* &tail,int data){
    // empty LL
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail= newNode;
    }

    // LL is not empty
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<endl;
}


int main(){
    Node* head = NULL;
    Node* tail =NULL;
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);
    printLL(head);
}