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
// insertion at head
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

// insertion at tail

void insertAtTail(Node* &head,Node* &tail,int data){
    // LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head=newNode;
        tail=newNode;
    }
    // LL is not empty
    else{
        Node* newNode = new Node(data);
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
}

// length find
int findLength(Node* &head ) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;
}
// insert At Any Position

void insertAtPosition(Node* &head,Node* &tail,int data,int position){
    // LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail= newNode;
    }

    else{
        int length = findLength(head);

        if(position == 1){
            insertAtHead(head,tail,data);
        }

        else if(position == length+1){
            insertAtTail(head,tail,data);
        }

        else{
            Node* newNode = new Node(data);
            Node* prevNode =NULL;
            Node* currNode =head;

            while(position !=1){
                position--;
                prevNode=currNode;
                currNode =currNode->next;
            }
            prevNode->next=newNode;
            newNode->prev=prevNode;
            newNode->next=currNode;
            currNode->prev=newNode;
        }
    }
}

// printing LL
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

    insertAtPosition(head,tail,45,2);
    printLL(head);

}