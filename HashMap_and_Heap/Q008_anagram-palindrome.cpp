#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool anagarmSolution(string& str)
{
    int arr[256]={0};
    for (int i = 0; i < str.length(); i++)
    {
        arr[str[i]]++;
    }

    int oddCount = 0;
    for (int i = 0; i < 256; i++)
    {
        if((arr[i]&1)!=0) oddCount++;
    }

    return oddCount>1?false:true;
}

void solve()
{
    string str;
   cin>>str;

    cout << (anagarmSolution(str) ? "Yes" : "No")<<endl;
}

int main()
{
    solve();
    return 1;
}