#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define ll long long int

void nextLargestElement(vector<ll> &arr, int n)
{
    if (n == 0 || n == 1)
    {
        cout << -1;
        return;
    }

    vector<ll> ans(n, -1);

    stack<ll> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (st.size() > 0 && arr[i] > arr[st.top()])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void solve()
{
    int t, n;
    cin >> t;
    while (t-- > 0)
    {
        cin >> n;
        vector<ll> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        nextLargestElement(arr, n);
    }
}

int main()
{
    solve();
    return 0;
}