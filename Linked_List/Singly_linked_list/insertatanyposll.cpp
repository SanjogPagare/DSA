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

// insertion at tail

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

int findLength(Node* &head ) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;
}

void print(Node* head){
    Node* temp= head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<endl;
}

void insertAtPosition(Node* &head,Node* &tail,int data,int position){
    int length = findLength(head);

    if(position == 1){
        insertAtHead(head,tail,data);
    }

    else if(position == length+1){
        insertAtTail(head,tail,data);
    }

    else{
        //ye logic important hai
        // step 1 : create new node 
        Node* newNode = new Node(data);

        // traverse to the curr and pre position
        Node* prev = NULL;
        Node* curr = head;

        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }
        // step3: attach prev to new node
        prev->next= newNode;
        //step 4: attach newNode to curr
        newNode->next = curr;
    }
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
    insertAtPosition(head,tail,80,100);
    print(head);
}