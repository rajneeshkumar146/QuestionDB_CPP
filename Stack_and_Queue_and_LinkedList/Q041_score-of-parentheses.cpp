#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

int scoreOfParentheses(string s)
{
    stack<int> st;
    st.push(0);

    int i = 0;
    while (i < s.length())
    {
        if (s[i] == '(')
            st.push(0);
        else
        {

            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            int val = b + max(2 * a, 1);
            st.push(val);
        }
        i++;
    }

    return st.top();
}

void solve()
{
    string str;
    cin >> str;

    cout << scoreOfParentheses(str) << endl;
}

int main(int args, char **argv)
{
    solve();
    return 1;
}