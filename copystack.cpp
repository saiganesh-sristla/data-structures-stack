#include<iostream>
#include<stack>
using namespace std;

stack<int> copyStack(stack<int> &input){
    stack<int> temp;

    while(! input.empty()){
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }

    stack<int> result;

    while(! temp.empty()){
        int curr = temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}

void copyStackRecursively(stack<int> &input, stack<int> &result){
    if(input.empty()) return;

    int curr = input.top();
    input.pop();
    copyStackRecursively(input, result);
    result.push(curr);
}

int main(){
    // stack<int> st;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    
    // stack<int> result = copyStack(st);

    // while(! result.empty()){
    //     cout << result.top() << endl;
    //     result.pop();
    // }

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    
    stack<int> result;
    copyStackRecursively(st, result);

    while(! result.empty()){
        cout << result.top() << endl;
        result.pop();
    }

    return 0;
}