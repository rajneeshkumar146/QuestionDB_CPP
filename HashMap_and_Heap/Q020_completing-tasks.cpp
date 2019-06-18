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

        int m, n;
        cin >> m >> n;
        int arr[1001] = {0};
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            arr[a] = 1;
        }

        vector<int> even, odd;
        int count = 0;
        for (int i = 1; i <= m; i++)
        {
            if (arr[i] == 0 && (count % 2 == 0))
            {
                even.push_back(i);
                count++;
            }
            else if (arr[i] == 0 && (count % 2 != 0))
            {
                odd.push_back(i);
                count++;
            }
        }

        for (int i = 0; i < even.size(); i++)
            cout << even[i] << " ";
        cout << endl;

        for (int i = 0; i < odd.size(); i++)
            cout << odd[i] << " ";
        cout << endl;
    }

    return 0;
}