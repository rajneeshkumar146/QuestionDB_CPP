#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
    Node() {}
};

void deleteNode(struct Node **head, int key)
{
    Node *node = *head;
    Node *prev = NULL;
    while (node->data != key)
    {
        prev = node;
        node = node->next;
    }

    Node *del = node;
    prev->next = node->next;

    // delete del;
}
/* Function to reverse the linked list */
void reverse(struct Node **head_ref)
{
    Node *node = *head_ref;

    Node *prev = NULL;
    while (node->next != *head_ref)
    {
        Node *next = node->next;
        node->next = prev;

        prev = node;
        node = next;
    }

    Node *shead = node->next;
    node->next = prev;
    prev = node;

    shead->next = node;
    *head_ref = node;

    *head_ref = prev;
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
        curr->next = new Node(ele);
        curr = curr->next;
    }
}

int main(int args, char **argv)
{
    solve();
    return 1;
}
