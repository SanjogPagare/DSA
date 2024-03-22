#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        arr = new int[size];
        this->size=size;
        this->top=-1;
    }
    // push element
    void push(int val){
        if(top >= size-1){
            cout<<"Overflow"<<endl;
            return;
        }
        else{
            top++;
            arr[top]=val;
        }
    }

    //pop element
    void pop(){
        if(top==-1){
            cout<<"UnderFlow"<<endl;
        }
        else{
            top--; 
        }
    }
    // get Top element 
    int getTop(){
        if(top==-1){
            cout<<"There is no element in Stack"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }
    // Check Stack is empty or not 
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    // check size of stack
    int getSize(){
        if(top==-1){
            return 0;
        }
        else{
            return top+1;
        }
    }
    // Printing stack
    void print(){
        for(int i=0;i<getSize();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};




int main(){
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.print();
    cout<<"size of stack is : "<<st.getSize()<<endl;
    cout<<"Top element is : "<<st.getTop()<<endl;
    st.pop();
    st.print();
    cout<<"size of stack is : "<<st.getSize()<<endl;
    cout<<"Top element is : "<<st.getTop()<<endl;
    st.push(60);
    st.print();
    cout<<"size of stack is : "<<st.getSize()<<endl;
    cout<<"Top element is : "<<st.getTop()<<endl;
    st.push(30);
    cout<<"size of stack is : "<<st.getSize()<<endl;
    cout<<"Top element is : "<<st.getTop()<<endl;
    if(st.isEmpty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
    st.pop();
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.print();
    cout<<"size of stack is : "<<st.getSize()<<endl;
    cout<<"Top element is : "<<st.getTop()<<endl;
    st.pop();
    if(st.isEmpty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
}