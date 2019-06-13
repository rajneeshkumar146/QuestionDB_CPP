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

ListNode *reverse(ListNode *node)
{
    ListNode *prev = NULL;
    while (node != NULL)
    {
        ListNode *next = node->next;
        node->next = prev;

        prev = node;
        node = next;
    }

    return prev;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    l1 = reverse(l1);
    l2 = reverse(l2);

    ListNode *head = new ListNode(-1); //dummy.
    ListNode *itr = head;

    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = carry + (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0);

        carry = sum / 10;
        sum = sum % 10;

        cout << l1->val << " " << l2->val << " @ " << sum << " " << carry << endl;

        itr->next = new ListNode(sum);
        itr = itr->next;

        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }

    return reverse(head->next);
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
    int n, m;
    cin >> n;
    ListNode *l1 = new ListNode(-1);
    ListNode *itr1 = l1;

    ListNode *l2 = new ListNode(-1);
    ListNode *itr2 = l2;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        itr1->next = new ListNode(ele);
        itr1 = itr1->next;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int ele;
        cin >> ele;
        itr2->next = new ListNode(ele);
        itr2 = itr2->next;
    }

    display(addTwoNumbers(l1->next, l2->next));
}

int main(int args, char **argv)
{
    solve();
    return 1;
}
