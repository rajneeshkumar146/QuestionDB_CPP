#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
void nextGreater(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(0);
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        while (st.size() > 0 && arr[i] > arr[st.top()])
        {
            ans += arr[i];
            st.pop();
        }
        st.push(i);
    }

    cout << ans << endl;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    nextGreater(arr, n);
}

int main(int args, char **argv)
{
    solve();
    return 0;
}
