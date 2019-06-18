#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
    unordered_map<int, int> umap;
    int freq[26] = {0};
    for (char ch : p)
        freq[ch - 'a']++;

    int i = -1;
    int j = 0;
    while (j < s.length() && i < j)
    {
        
        umap[j]++;
    }
}

void solve()
{
}

int main(int args, char **argc)
{
    solve();
    return 1;
}