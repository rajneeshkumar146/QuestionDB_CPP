#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *deleteMid(Node *head)
{
    Node *prev = nullptr;
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;

        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != nullptr)
        prev->next = slow->next;
    else
        NULL;
    return head;
}

void display(Node *node)
{
    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->next;
    }

    cout << endl;
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
        curr->next = new Node();
        curr->next->data = ele;
        curr = curr->next;
    }
}

int main(int args, char **argv)
{
    solve();
    return 1;
}
