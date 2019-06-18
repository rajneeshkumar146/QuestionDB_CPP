#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> umap;
    for (string str : strs)
    {
        int freqMap[26] = {0};
        for (auto ch : str)
            freqMap[ch - 'a']++;

        string s;
        for (int j = 0; j < 26; j++)
        {
            s = s + (char)(j + 'a') + to_string(freqMap[j]);
        }

        umap[s].push_back(str);
    }

    vector<vector<string>> ans;
    for (auto i : umap)
    {
        ans.push_back(i.second);
    }

    return ans;
}

void solve()
{
}

int main(int args, char **argc)
{
    solve();
    return 1;
}
