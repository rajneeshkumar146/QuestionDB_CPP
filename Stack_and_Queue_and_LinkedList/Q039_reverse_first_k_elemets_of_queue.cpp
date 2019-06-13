// #include<bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;
#define ll long long

queue<ll> modifyQueue(queue<ll> q, int k)
{
    queue<ll> ans;
    stack<ll> st;
    while (k-- > 0)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        ans.push(st.top());
        st.pop();
    }

    while (!q.empty())
    {
        ans.push(q.front());
        q.pop();
    }

    return ans;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    queue<ll> q;
    while (n-- > 0)
    {
        ll a;
        cin >> a;
        q.push(a);
    }
    queue<ll> ans = modifyQueue(q, k);
    while (!ans.empty())
    {
        int a = ans.front();
        ans.pop();
        cout << a << " ";
    }
    cout << endl;
}

int main()
{
    solve();
    return 1;
}