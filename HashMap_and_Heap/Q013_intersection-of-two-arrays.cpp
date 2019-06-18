#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < nums1.size(); i++)
        umap[nums1[i]] = 0;

    for (int i : nums2)
    {
        if (umap.find(i) != umap.end())
            umap[i] = 1;
    }

    vector<int> sol;
    for (auto i : umap)
        if (umap[i.first] == 1)
            sol.push_back(i.first);

    return sol;
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