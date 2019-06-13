#include <iostream>
#include <climits>
#include <vector>
using namespace std;

bool find132pattern(vector<int> &nums)
{
    int minele = INT_MAX;
    for (int j = 0; j < nums.size(); j++)
    {
        for (int k = j + 1; k < nums.size(); k++)
        {
            if (nums[k] < nums[j] && minele < nums[k])
            {
                return true;
            }
            minele = min(minele, nums[j]);
        }
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << boolalpha << find132pattern(arr);
}

int main(int args, char **argv)
{
    solve();
    return 0;
}