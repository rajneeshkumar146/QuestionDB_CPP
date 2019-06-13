#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define long long int ll

struct petrolPump
{
    int petrol;
    int distance;
};


int tour(petrolPump* p, int n)
{

    int start = 0;
    int deficite = 0;
   
    for (int i = 0; i < n; i++)
    {
        deficite += p[i].petrol - p[i].distance;

        if (deficite < 0)
        {
            start = i + 1;
            deficite = 0;
        }
    }

    if (start >= n)
    {
        return -1;
    }

    for (int i = 0; i <= start; i++)
    {
        deficite += p[i].petrol - p[i].distance;
        if (deficite < 0)
        {
            return -1;
        }
    }

    return start;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        petrolPump* p = new petrolPump[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;

        cout << tour(p, n) << endl;
    }
}
