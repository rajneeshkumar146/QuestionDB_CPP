#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> board(r + 1, vector<int>(c + 1, 0));
queue<pair<int, pair<int, int>>> que;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> board[i][j];
            if(board[i][j]==2){
                que.push({i,{j,0}});
            }
        }
    }

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int ans = 0;
    while (que.size() > 0)
    {
        pair<int, pair<int, int>> p = que.front();
        que.pop();

        ans=max(ans,p.second.second);
        for (int i = 0; i < 4; i++)
        {
            int row = dir[i][0] + p.first;
            int col = dir[i][1] + p.second.first;

            if (row <= r && col <= c && row >= 1 && col >= 1 && board[row][col]==1)
            {
                board[row][col] = 2;
                que.push({row, {col, p.second.second + 1}});
            }
        }
    }

    
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if(board[i][j]==1){
                cout<<-1<<endl;
                return;
            }
        }
    }

    cout<<ans<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();

    return 0;
}