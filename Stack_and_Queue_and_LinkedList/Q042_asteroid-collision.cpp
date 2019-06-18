#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


vector<int> asteroidCollision(vector<int> &asteroids)
{
    if (asteroids.size() == 0 || asteroids.size() == 1)
        return asteroids;

    stack<int> st;
    int i = 0;
    while (i < asteroids.size())
    {
        if (asteroids[i] > 0)
            st.push(asteroids[i]);
        else if (!st.empty() && asteroids[i] < 0 && st.top() > 0)
        {
            int val = st.top();

            if (val < -asteroids[i])
            {
                st.pop();
                continue;
            }
            else if (val == -asteroids[i])
                st.pop();
        }
        else
            st.push(asteroids[i]);

        i++;
    }

    vector<int> ans(st.size(), 0);
    for (int i = st.size() - 1; i >= 0; i--)
    {
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int main()
{
    solve();
    return 1;
}