#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> list;
    if (nums.size() < 4)
        return list;

    sort(nums.begin(), nums.end());

    if (4 * nums[0] > target || 4 * nums[nums.size() - 1] < target)
        return list;

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) //to avoid dupliacte from i.
            continue;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1]) //to avoid dupliacte from j.
                continue;

            int le = j + 1;
            int ri = nums.size() - 1;

            int reqSum = target - (nums[i] + nums[j]);
            while (le < ri)
            {
                int sum = nums[le] + nums[ri];
                if (sum < reqSum)
                    le++;
                else if (sum > reqSum)
                    ri--;
                else
                {
                    vector<int> res;
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    res.push_back(nums[le]);
                    res.push_back(nums[ri]);

                    list.push_back(res);

                    le++;
                    ri--;
                    if (le < ri && nums[le] == nums[le - 1]) //avoid dupliacte from inner traversal loop.
                        le++;
                    if (le < ri && nums[ri] == nums[ri + 1]) //avoid dupliacte from inner traversal loop.
                        ri--;
                }
            }
        }
    }
    return list;
}

int main(int args, char **argv)
{
    int n, target;
    cin >> target >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> list = fourSum(nums, target);
    cout << "[";
    for (int i = 0; i < list.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < list[i].size(); j++)
        {
            if (j == list[i].size() - 1)
                cout << list[i][j];
            else
                cout << list[i][j] << ",";
        }
        if (i == list.size() - 1)
            cout << "]";
        else
            cout << "],";
    }
    cout << "]";
}

//rajneesh.
// 0 6
// 1 0 -1 0 -2 2
