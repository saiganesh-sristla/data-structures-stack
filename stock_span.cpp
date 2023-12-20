#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> pge(vector<int> input, int n)
{
    vector<int> output(n, 1);
    stack<int> st;

    st.push(n-1);
    for (int i = n-2; i >= 0; i--)
    {
        while ((!st.empty()) && input[i] > input[st.top()])
        {
            output[st.top()] = st.top() - i;
            st.pop();
        }
        st.push(i);
    }
    return output;
}

int main()
{
    vector<int> v = {100,80,60,70,60,75,85};
    int n = v.size();

    vector<int> result = pge(v, n);

    cout << "Stock Span: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
