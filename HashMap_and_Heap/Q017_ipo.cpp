#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

struct project
{
    int profit;
    int capital;
    project(int profit, int capital)
    {
        this->profit = profit;
        this->capital = capital;
    }

    project()
    {
    }
};

static bool projectCapitalComparator(project one, project two)
{
    return one.capital < two.capital;
}

struct projectProfitComparactor
{
    bool operator()(const project &one, const project &two)
    {
        return two.profit > one.profit;
    }
};

int findMaximizedCapital(int k, int W, vector<int> &Profits, vector<int> &Capital)
{
    int size = Profits.size();
    vector<project> arr(size, project());
    for (int i = 0; i < size; i++)
    {
        arr[i] = project(Profits[i], Capital[i]);
    }

    sort(arr.begin(), arr.end(), projectCapitalComparator);

    priority_queue<project, vector<project>, projectProfitComparactor> que;

    int i = 0;
    while (i < size)
    {
        project pro = arr[i];
        if (pro.capital <= W)
            que.push(pro);
        else
            break;
        i++;
    }

    while (k > 0 && que.size() > 0)
    {
        project p = que.top();
        que.pop();
        W += p.profit;
        k--;
        while (i < size)
        {
            project pro = arr[i];
            if (pro.capital <= W)
                que.push(pro);
            else
                break;
            i++;
        }
    }

    return W;
}
void solve()
{

    int k, w;
    cin >> k >> w;
    int n, m;
    cin >> n >> m;rm 
    vector<int> Profits(n, 0);
    vector<int> Capitals(m, 0);

    for (int i = 0; i < n; i++)
        cin >> Profits[i];

    for (int i = 0; i < m; i++)
        cin >> Capitals[i];

    cout << findMaximizedCapital(k, w, Profits, Capitals) << endl;
}

int main()
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
    return 0;
}

// 2 0
// 3 3
// 1 2 3
// 0 1 1