#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *arrange(Node *head)
{

    Node *cons = new Node();
    Node *itrc = cons;

    Node *vow = new Node();
    Node *itrv = vow;

    while (head != nullptr)
    {
        char ch = head->data;
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            itrv->next = head;
            head = head->next;
            itrv = itrv->next;
            itrv->next = NULL;
        }
        else
        {
            itrc->next = head;
            head = head->next;
            itrc = itrc->next;
            itrc->next = NULL;
        }
    }

    itrv->next = cons->next;
    return vow->next;
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
