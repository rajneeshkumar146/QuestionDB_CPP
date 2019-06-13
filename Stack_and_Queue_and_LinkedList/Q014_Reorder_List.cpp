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

ListNode *reversePtr(ListNode *node)
{
    ListNode *prev = nullptr;

    while (node != nullptr)
    {
        ListNode *next = node->next;
        node->next = prev;

        prev = node;
        node = next;
    }
    return prev;
}

void reorderList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *nhead = slow->next;
    slow->next = nullptr;

    ListNode *rhead = head;

    nhead = reversePtr(nhead);
    while (head != nullptr && nhead != nullptr)
    {
        ListNode *temp1 = head->next;
        ListNode *temp2 = nhead->next;

        head->next = nhead;
        nhead->next = temp1;

        head = temp1;
        nhead = temp2;
    }
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
