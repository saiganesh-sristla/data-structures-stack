#include<iostream>
#include<stack>
using namespace std;

void removeAtBottom(stack<int> &st){
    stack<int> temp;

    while(! st.empty()){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    temp.pop();

    while(! temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
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

    removeAtBottom(st);
    printStack(st);
    return 0;
}