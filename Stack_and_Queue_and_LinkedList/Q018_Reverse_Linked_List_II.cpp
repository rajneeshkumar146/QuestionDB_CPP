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

ListNode *reverse(ListNode *st, ListNode *end)
{
    ListNode *prev = nullptr;
    while (st != end->next)
    {
        ListNode *next = st->next;
        st->next = prev;

        prev = st;
        st = st->next;
    }

    return prev;
}

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (head == nullptr || m == n)
        return head;

    stack<ListNode *> st;

    ListNode *left = head;
    ListNode *right = head;

    ListNode *prev = nullptr;

    for (int i = 1; i <= n; i++)
    {
        while (i >= m && i <= n)
        {
            right = right->next;
            i++;
        }

        if (left != right)
        {
            if (prev != nullptr)
                prev->next = reverse(left, right);
            else
                head = reverse(left, right);

            left->next = right->next;
            i--;
        }
        else
        {
            left = left->next;
            right = right->next;
        }
    }
    return head;
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
