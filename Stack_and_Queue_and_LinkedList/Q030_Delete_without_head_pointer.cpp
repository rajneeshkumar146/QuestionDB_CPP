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

void deleteNode(Node *node)
{
    node->data = node->next->data;
    node->next = node->next->next;
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
