#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
bool canReorderDoubled(vector<int> &A)
{
    unordered_map<int, int> umap;
    for (int i : A)
        umap[i]++;

    sort(A.begin(), A.end());
    for (auto i : A)
    {
        if (umap[i] == 0)  //it is already proccessed,ex -4 already reduce frequency of -2.
            continue;
        int val = i < 0 ? i / 2 : 2 * i;  //for -4<-2,to -4 ke liye -2 ki frequnecy reduce krni hai. for positive double dhoondo.
        if (umap[val] == 0)   //jaha jane wala tha vo phele se hi zero pada hai to return flase.
            return false;
        else
            umap[val]--;
        umap[i]--;
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    canReorderDoubled(arr);
}

int main()
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
    return 0;
}