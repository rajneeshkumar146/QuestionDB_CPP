#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void groupk_Anagrams(vector<string> &strs)
{
    unordered_map<string, int> umap;
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

        umap[s]++;
    }

    vector<int> ans;
    for (auto i : umap)
    {
        ans.push_back(i.second);
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> strs;
    while (n-- > 0)
    {
        string str;
        cin >> str;
        strs.push_back(str);
    }

    groupk_Anagrams(strs);
}

int main(int args, char **argc)
{
    // int t;cin>>t;
    // while(t-->0)
    solve();
    return 1;
}
