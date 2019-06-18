#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void sumEqualToSum(vector<int> &arr)
{
    unordered_map<int, pair<int, int>> umap;
    for (int i = 0; i < arr.size(); i++)
        for (int j = i + 1; j < arr.size(); j++)
        {
            int sum = arr[i] + arr[j];
            if (umap.find(sum) == umap.end())
                umap[sum] = {i, j};
            else
            {
                cout << 1 << endl;
                return;
            }
        }

    cout << 0 << endl;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sumEqualToSum(arr);
}

int main()
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
        solve();
    return 0;
}