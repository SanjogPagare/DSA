#include<iostream>
using namespace std;

// making class for making queue

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;


    // Queue(){
    //     front=-1;
    //     rear=-1;
    // }
    Queue(int size){
        arr = new int[size];
        this->size=size;
        front=-1;
        rear=-1;
    }
    // fuction for push opertaion
    void push(int val){
        // check full
        if(rear == size-1){
            cout<<"queue is full"<<endl;
        }
        // not full
        else if(rear==-1 && front==-1) {
            rear++;
            front++;
            arr[rear]=val;
        }
        else{
            rear++;
            arr[rear]=val;
        }

    }
    // pop operation function
    void pop(){
        //underflow condation
        if(front==-1 && rear==-1){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        else if(front == rear){
            // empty case--> single element
            arr[rear]=-1;
            front =-1;
            rear = -1;
        }
        else{
            arr[front]=-1;
            front++;
        }
    }
    // Queue is empty or not
    bool empty(){
        if(front == -1 && rear==-1){
            return true;
        }
        else{
            return false;
        }
    }
    // size of Queue
    int getSize (){
        if(rear==-1 && front==-1){
            return 0;
        }
        else{
            return rear-front+1;
        }
    }

    // front element
    int getFront(){
        if(front==-1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }
    // rear element
    int getRear(){
        if(rear==-1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            return arr[rear];
        }
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}; 


int main(){
    Queue q(5);
    q.print();
    q.push(10);
    q.print();
    q.push(20);
    q.print();
    q.push(30);
    q.print();
    q.push(40);
    q.print();
    q.push(50);
    q.print();
    cout<<"size of queue : "<<q.getSize()<<endl;
    q.pop();
    q.print();
    cout<<"size of queue : "<<q.getSize()<<endl;
    q.pop();
    q.print();
    cout<<"size of queue : "<<q.getSize()<<endl;
    q.pop();
    q.print();
    cout<<"size of queue : "<<q.getSize()<<endl;
    q.pop();
    q.print();
    cout<<"size of queue : "<<q.getSize()<<endl;
    cout<<"front element : "<<q.getFront()<<endl;
     q.pop();
     q.print();
     cout<<"size of queue : "<<q.getSize()<<endl;
     cout<<"front element : "<<q.getFront()<<endl;
     cout<<"rear element : "<<q.getRear()<<endl;
     if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
    q.push(60);
    q.print();
}