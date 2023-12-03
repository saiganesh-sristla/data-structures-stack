#include<iostream>
#include<stack>
using namespace std;

void reverseStack(stack<int> &st){
    stack<int> t1, t2;

    while(! st.empty()){
        int curr = st.top();
        st.pop();
        t1.push(curr);
    }

    while(! t1.empty()){
        int curr = t1.top();
        t1.pop();
        t2.push(curr);
    }

    while(! t2.empty()){
        int curr = t2.top();
        t2.pop();
        st.push(curr);
    }
}

void insertAtBottom(stack<int> &st, int x){
    stack<int> temp;

    while(! st.empty()){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(x);

    while(! temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
}


void reverseRecursively(stack<int> &st){
    if(st.empty()){
        return;
    }

    int curr = st.top();
    st.pop();
    reverseRecursively(st);
    insertAtBottom(st, curr);

}


void printStack(stack<int> s){
    while(!s.empty()){
        cout << s.top() << "\n";
        s.pop();
    }
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverseRecursively(st);
    printStack(st);
    return 0;
}