#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> chess(n + 1, vector<int>(n + 1, 0));
    int sr, sc, er, ec;
    cin >> sr >> sc >> er >> ec;

    queue<pair<int, pair<int, int>>> que;
    que.push({sr, {sc, 0}});

    int dir[8][2] = {{2, 1}, {1, 2}, {-2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

    int ans = 1;
    chess[sr][sc] = 1;
    while (que.size() > 0)
    {
        pair<int, pair<int, int>> p = que.front();
        que.pop();

        if (p.first == er && p.second.first == ec)
        {
            ans = p.second.second;
            break;
        }

        for (int i = 0; i < 8; i++)
        {
            int row = dir[i][0] + p.first;
            int col = dir[i][1] + p.second.first;

            if (row <= n && col <= n && row >= 1 && col >= 1 && chess[row][col] == 0)
            {
                chess[row][col] = 1;
                que.push({row, {col, p.second.second + 1}});
            }
        }
    }

    cout << ans;
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();

    return 0;
}