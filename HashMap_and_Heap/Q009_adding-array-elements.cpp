#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void addingArrayEleSolution(vector<int> &arr, int k)
{

    sort(arr.begin(), arr.end());
    priority_queue<int, vector<int>, greater<int>> que;

    int greaterKcount = 0;
    int cnt = 0;
    //total eelement graeter than k.
    int j = arr.size() - 1;
    while (j >= 0)
    {
        if (arr[j] >= k)
        {
            j--;
            greaterKcount++;
        }
        else
            break;
    }

    // unresolved points are j.
    int i = 0;
    while (i < j)
    {
        if (arr[i] + arr[j] >= k)
        {
            cnt++;
            i++;
            j--;
        }
        else
        {
            que.push(arr[i]);
            i++;
        }
    }

    if (j != -1 && i == j)
        que.push(arr[j]);

    int count = 0;
    while (que.size() > 0 && que.top() < k)
    {
        int num1 = que.top();
        que.pop();
        int num2 = que.top();
        que.pop();
        int nsum = num1 + num2;
        if (nsum >= k)
            greaterKcount++;
        else
        {
            que.push(num1 + num2);
            count++;
        }
    }
    cout << count << endl;
}

int main(int args, char **argv)
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}