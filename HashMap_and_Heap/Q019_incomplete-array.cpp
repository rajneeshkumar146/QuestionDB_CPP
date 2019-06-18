#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#include <unordered_set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {

        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int uset[1001] = {0};
        int minele = INT_MAX;
        int maxele = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            uset[arr[i]] = 1;
            minele = min(minele, arr[i]);
            maxele = max(maxele, arr[i]);
        }

        int count = 0;
        for (int i = minele; i <= maxele; i++)
        {
            if (uset[i] == 0)
            {
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}