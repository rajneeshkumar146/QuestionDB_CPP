#include <iostream>
using namespace std;

void helpNobita(string &str1)
{
    int freq[27] = {0};

    for (int i = 0; i < str1.length(); i++)
    {
        char ch = str1[i];
        freq[ch - 'a' + 1]++;
    }

    int ans = 0;
    for (int i = 1; i <= 26; i++)
    {
        if (freq[i] != 0)
        {
            if (freq[i] % 2 == 0 && i % 2 == 0)
                ans++;
            else if (freq[i] % 2 != 0 && i % 2 != 0)
                ans++;
        }
    }
    cout << (ans % 2 == 0 ? "EVEN" : "ODD") << endl;
}

void solve()
{
    string str1;
    cin >> str1;

    helpNobita(str1);
}
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}