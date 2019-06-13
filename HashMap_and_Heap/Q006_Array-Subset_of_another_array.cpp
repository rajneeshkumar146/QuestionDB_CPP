#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

bool SubsetProblem(vector<int>& arr1, vector<int>& arr2)
{
    unordered_map<int, int> umap;
    for (int i : arr1)
    {
        umap[i]++; //storing element of one array.
    }

    for (int i : arr2)
    {
        if (umap.find(i)==umap.end())
        {
           return false;
        }
    }
    
    return true;
}

void solve()
{
    int n, m;
    cin >> n>>m;

    vector<int> arr1(n, 0);
    vector<int> arr2(m, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    cout<<(SubsetProblem(arr1,arr2)?"Yes":"No")<<endl;
    
}

int main(int args, char **argv)
{
    solve();
    return 0;
}