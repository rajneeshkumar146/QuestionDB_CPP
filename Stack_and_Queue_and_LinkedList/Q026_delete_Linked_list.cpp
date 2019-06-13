#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNodes(ListNode *node)
{

    while (node != nullptr)
    {
        ListNode *del = node;
        node = node->next;
        delete del;
    }

    node = NULL;
}

void display(ListNode *node)
{
    while (node != nullptr)
    {
        cout << node->val << " ";
        node = node->next;
    }

    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    ListNode *head = new ListNode(-1);
    ListNode *curr = head;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        curr->next = new ListNode(ele);
        curr = curr->next;
    }
}

int main(int args, char **argv)
{
    solve();
    return 1;
}
