#include<iostream>
#include<stack>
using namespace std;

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

void insertAtBottomRecursively(stack<int> &st, int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int curr = st.top();
    st.pop();
    insertAtBottomRecursively(st, x);
    st.push(curr);
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
    // printStack(st);

    insertAtBottomRecursively(st, 100);
    printStack(st);
    

    return 0;
}