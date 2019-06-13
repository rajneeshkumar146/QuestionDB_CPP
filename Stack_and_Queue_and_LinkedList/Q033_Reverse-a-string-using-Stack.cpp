#include <bits/stdc++.h>
using namespace std;

void reverse(char *str, int n)
{
    for (int i = 0, j = n - 1; i <= j; i++, j--)
    {
        swap(str[i], str[j]);
    }
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        char str[10000];
        cin >> str;
        long long int len = strlen(str);
        reverse(str, len);
        cout << str;
        cout << endl;
    }
    return 0;
}