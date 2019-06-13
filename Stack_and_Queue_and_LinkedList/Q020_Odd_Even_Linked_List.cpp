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

ListNode *oddEvenList(ListNode *head)
{

    ListNode *odd = new ListNode(-1);
    ListNode *itro = odd;

    ListNode *even = new ListNode(-1);
    ListNode *itre = even;

    while (head != nullptr)
    {

        itro->next = head;
        itre->next = head->next;

        itro = itro->next;
        itre = itre->next;

        head = head->next;
        if (head != nullptr)
            head = head->next;
        else
            break;
    }

    itro->next = even->next;
    return odd->next;
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
