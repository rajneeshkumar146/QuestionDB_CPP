#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int> &A, int K)
{
    priority_queue<pair<double, pair<int, int>>> que; //fraction,divisor_index,dividend_index

    for (int i = 0; i < A.size(); i++)
    {
        que.push({-1.0 * A[i] / A.back(), {i, A.size() - 1}});
    }

    while (--K > 0)
    {
        pair<int, int> p=que.top().second;
        que.pop();

        p.second--;
        que.push({-1.0*A[p.first]/A[p.second],{p.first,p.second}});
    }

    vector<int> ans;
    ans.push_back(A[que.top().second.first]);
    ans.push_back(A[que.top().second.second]);
    return ans;
}

int main()
{
    int k, n;
    cin >> k >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

     arr = kthSmallestPrimeFraction(arr, k);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}