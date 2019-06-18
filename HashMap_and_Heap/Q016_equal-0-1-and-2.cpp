#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void equal0_1_and2(string &str)
{

    int num[3] = {0}; //int zero = 0, one = 0, two = 0;
    unordered_map<string, int> umap;

    for (int i = 0; i <= str.length(); i++)
    {
        int hasing1 = num[1] - num[0]; //ones-zeros.
        int hasing2 = num[2] - num[1]; //twos-ones.
        string s = to_string(hasing1) + "*" + to_string(hasing2);
        if (i != str.length())
        {
            int ch = str[i] - '0';
            num[ch]++; //prefix sum digits.(similar to array). zeros++,ones++,two++.
        }
        umap[s]++;
    }

    int ans = 0;
    for (auto itr : umap)
    {
        int n = itr.second;
        ans += (n * (n - 1)) >> 1;
    }

    cout << ans << endl;
}

void solve()
{
    string n;
    cin >> n;
    equal0_1_and2(n);
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}