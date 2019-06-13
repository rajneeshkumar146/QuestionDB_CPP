#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < C.size(); i++)
    {
        for (int j = 0; j < D.size(); j++)
        {
            int sum = C[i] + D[j];
            umap[sum]++;
        }
    }

    int res = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            int sum = A[i] + B[j];
            sum *= -1;
            res += umap[sum];
        }
    }
    return res;
}

int main(int args, char **argv)
{
    int n;
    cin >> n;
    vector<int> A(n, 0);
    vector<int> B(n, 0);
    vector<int> C(n, 0);
    vector<int> D(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> C[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> D[i];
    }

    cout << fourSumCount(A, B, C, D);
}
