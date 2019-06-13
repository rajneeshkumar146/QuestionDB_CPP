#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void moveZeroes(struct Node **head)
{
    if ((*head) == nullptr || (*head)->next == nullptr)
        return;

    Node *curr = (*head)->next;
    Node *prev = *head;

    while (curr != nullptr)
    {
        if (curr->data == 0)
        {
            Node *temp = curr;

            prev->next = curr->next;
            curr = curr->next;

            temp->next = *head;
            *head = temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    void solve()
    {
        int n;
        cin >> n;
        Node *head = new Node();
        Node *curr = head;
        for (int i = 0; i < n; i++)
        {
            char ele;
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
