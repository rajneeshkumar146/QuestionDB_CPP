#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.
// You may assume the integer do not contain any leading zero, except the number 0 itself.
// The digits are stored such that the most significant digit is at the head of the list.
// Input: [1,2,3]
// Output: [1,2,4]

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

ListNode *plusOne(ListNode *l1)
{
    if (l1 == nullptr)
        return l1;

    l1 = reverse(l1);

    ListNode *head = new ListNode(-1); //dummy.
    ListNode *itr = head;

    int carry = 1;
    while (l1 != NULL || carry)
    {
        int sum = carry + (l1 != NULL ? l1->val : 0);

        carry = sum / 10;
        sum = sum % 10;

        itr->next = new ListNode(sum);
        itr = itr->next;

        if (l1 != NULL)
            l1 = l1->next;
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
