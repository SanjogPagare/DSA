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

// to insert node at head
void insertAtHead(Node* &head,Node* &tail,int data){ // always pass by reference
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


void insertAtTail(Node* &head,Node* &tail,int data){
    if(head == NULL){
        //empty LL
        // step 1 create new node
        Node* newNode = new Node(data);
        // step 2 there is only singe node so 
        //point head and tail to that node
        head = newNode;
        tail = newNode;
    }
    else{
        //not empty LL
        //step 1: create new node
        Node* newNode = new Node(data);
        //step 2: tail node ko attach krna h 
        tail->next=newNode;
        //stpe 3: update tail
        tail = newNode;
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

    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,50);
    insertAtTail(head,tail,60);
    insertAtTail(head,tail,700);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,30);

    print(head);

}