#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *rearrangeEvenOdd(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *odd = new Node();
    Node *even = new Node();

    Node *itro = odd;
    Node *itre = even;

    int count = 0;
    while (head != nullptr)
    {
        if ((count & 1) == 0) //even idx
        {
            itro->next = head;
            head = head->next;
            itro = itro->next;
            itro->next = nullptr;
        }
        else
        {
            itre->next = head;
            head = head->next;
            itre = itre->next;
            itre->next = nullptr;
        }
        count++;
    }

    itro->next = even->next;
    return odd->next;
}

void solve()
{
    int n;
    cin >> n;
    Node *head = new Node(-1);
    Node *curr = head;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        curr->next = new Node(ele);
        curr = curr->next;
    }
}

int main(int args, char **argv)
{
    solve();
    return 1;
}
