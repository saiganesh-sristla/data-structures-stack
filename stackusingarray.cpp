#include<iostream>
using namespace std;

class Stack{
    int capacity;
    int top;
    int* arr;
    public:

    Stack(int c){
        capacity = c;
        top = -1;
        arr = new int[c];
    }

    void push(int data){
        if(top == capacity - 1){
            cout << "Overflow\n";
            return; 
        }
        top++;
        arr[top] = data;
    }

    int pop(){
        if(top == -1){
            cout << "Underflow\n";
            return INT16_MIN;
        }
        top--;
    }

    int getTop(){
        if(top == -1){
            cout << "Underflow\n";
            return INT16_MIN;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == capacity - 1;
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