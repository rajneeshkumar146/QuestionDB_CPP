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
    if (head == nullptr)
        return head;
}

Node *deleteAllOccurances(Node *head, int x)
{
    Node *prev = nullptr;
    Node *node = head;

    while (node != NULL)
    {
        if (node->data == x)
        {
            if (prev != NULL)
            {
                Node *del = node;
                prev->next = node->next;
                node = node->next;

                delete del;
            }
            else
            {
                Node *del = node;
                head = node->next;

                delete del;
            }
        }
        else
        {
            prev = node;
            node = node->next;
        }
    }
    return head;
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
