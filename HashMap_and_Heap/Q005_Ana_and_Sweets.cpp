#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

void customerSolution(vector<int> &arr, int k)
{
    unordered_map<int, int> umap;

    int maxele = INT_MIN;
    for (int i : arr)
    {
        umap[i]++;
        maxele = max(maxele, umap[i]);
    }

    if (maxele > 2 * k)
        cout << 0;
    else
        cout << 1;
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
    int k;
    cin >> k;

    customerSolution(arr,k);
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    solve();
    return 0;
}