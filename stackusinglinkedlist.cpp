#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

class Stack{
    Node* head;
    int currSize;
    int capacity;
    public:

    Stack(int c){
        head = NULL;
        currSize = 0;
        capacity = c;
    }

    void push(int data){
        if(currSize == capacity){
            cout << "Overflow\n";
            return;
        }
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
        currSize++;
    }

    int pop(){
        if(head == NULL){
            cout << "Underflow\n";
            return INT16_MAX;
        }
        Node* new_head = head->next;
        int removedData = head->data;
        head->next = NULL;
        delete head;
        head = new_head;
        currSize--;
        return removedData;
    }

    int getTop(){
        if(head == NULL){
            cout << "Underflow\n";
            return INT16_MAX;
        }
        return head->data;
    }

    bool isEmpty(){
        return head == NULL;
    }

    bool isFull(){
        return currSize == capacity;
    }
};

int main(){
    Stack st = Stack(5);
    st.push(2);
    st.push(6);
    cout << st.getTop() << endl;
    st.push(3);
    st.push(3);
    st.push(3);
    cout << st.getTop() << endl;
    cout << st.isFull() << endl;
    st.push(3);
    cout << st.getTop() << endl;

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout << st.isEmpty() << endl;

    return 0;
}