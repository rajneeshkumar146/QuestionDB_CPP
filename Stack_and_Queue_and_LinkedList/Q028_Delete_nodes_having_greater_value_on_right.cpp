#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *compute(Node *head)
{
    if (head == nullptr)
        return head;

    stack<Node *> st;
    st.push(head);
    head = head->next;
    st.top()->next = nullptr;

    while (head != NULL)
    {
        Node *temp = head;

        head = head->next;
        temp->next = NULL;

        while (st.size() > 0 && st.top()->data < temp->data)
        {
            st.pop();
        }
        st.push(temp);
    }

    while (st.size() > 1)
    {
        Node *temp = st.top();
        st.pop();
        st.top()->next = temp;
    }

    return st.top();
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
