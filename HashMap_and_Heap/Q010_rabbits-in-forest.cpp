#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int numRabbits(vector<int> &answers)
{
    if (answers.size() == 0)
        return 0;

    unordered_map<int, int> umap;
    for (int i : answers)
        umap[i]++; //frequency.

    int ans = 0;
    for (auto i : umap)
    {
        int groupSize = i.first + 1;
        int noOfGroups = ceil(i.second * 1.0 / groupSize);
        ans += groupSize * noOfGroups;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> answers(n, 0);
    for (int i = 0; i < n; i++)
        cin >> answers[i];
}

int main()
{
    solve();
    return 0;
}