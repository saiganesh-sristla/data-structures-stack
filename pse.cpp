#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> pse(vector<int> input, int n)
{
    vector<int> output(n, -1);
    stack<int> st;

    st.push(n-1);
    for (int i = n-2; i >= 0; i--)
    {
        while ((!st.empty()) && input[i] < input[st.top()])
        {
            output[st.top()] = input[i];
            st.pop();
        }
        st.push(i);
    }
    return output;
}

int main()
{
    vector<int> v = {2, 5, 2, 4, 2, 6, 4, 1};
    int n = v.size();

    vector<int> result = pse(v, n);

    cout << "Previous Smaller Elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
