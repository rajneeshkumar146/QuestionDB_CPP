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

bool isPalindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *nhead = slow->next;
    slow->next = nullptr;

    nhead = reversePtr(nhead);

    while (head != nullptr && nhead != nullptr)
    {
        if (head->val != nhead->val)
            return false;

        head = head->next;
        nhead = nhead->next;
    }

    return true;
}
}

void solve()
{
}

int main(int args, char **argv)
{
    solve();
    return 1;
}
