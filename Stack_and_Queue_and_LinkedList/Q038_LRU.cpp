#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class LRU
{

    unordered_map<int, int> umap;
    list<int> dq;
    int size;

public:
    LRU(int n)
    {
        umap.clear();
        dq.clear();
        this->size = n;
    }

    void set(int x, int y)
    {
        if (umap.find(x) == umap.end())
        {
            if (dq.size() >= size)
            {
                int temp = dq.back();
                dq.pop_back();
                umap.erase(temp);
            }

            dq.push_front(x);
            umap[x] = y;
        }
        else
        {
            dq.remove(x);
            dq.push_front(x);
            umap[x] = y;
        }
    }

    int get(int x)
    {
        if (umap.find(x) == umap.end())
            return -1;
        else
        {
            dq.remove(x);
            dq.push_front(x);
            return umap[x];
        }
    }
};

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        LRU *l = new LRU(n);
        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            string a;
            cin >> a;
            if (a == "SET")
            {
                int aa, bb;
                cin >> aa >> bb;
                l->set(aa, bb);
            }
            else if (a == "GET")
            {
                int aa;
                cin >> aa;
                cout << l->get(aa) << " ";
            }
        }
        cout << endl;
    }
}

int main(int args, char **argv)
{
    solve();
    return 1;
}