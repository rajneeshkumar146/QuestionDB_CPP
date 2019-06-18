#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool areKAnagrams(string &str1, string &str2, int k)
{
    int freq[26] = {0};
    for (int i = 0; i < str1.length(); i++)
    {
        int ch = str1[i] - 'a';
        freq[ch]++;
    }

    for (int i = 0; i < str2.length(); i++)
    {
        int ch = str2[i] - 'a';
        freq[ch]--;
    }

    int ans = 0;
    int bal = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
            ans += freq[i];
        bal += freq[i];
    }
    return bal == 0 && ans <= k;
}

void solve()
{
    string str1, str2;
    cin >> str1 >> str2;
    int n;
    cin >> n;

    areKAnagrams(str1, str2, n);
}

int main(int args, char **argc)
{
    // int t;cin>>t;
    // while(t-->0)
    solve();
    return 1;
}
