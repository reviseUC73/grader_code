#include <iostream>
using namespace std;
typedef struct node
{
    int value;
    struct node *next;
    node(int v = 0, node *nxt = 0)
        : value(v), next(nxt) {}
} node;
void push(node *&s, int v)
{
    node *this_push = new node();
    this_push->next = nullptr;
    this_push->value = v;
    if (s != nullptr)
    {
        this_push->next = s;
    }
    s = this_push;
}
int pop(node *&s)
{
    int val = 0;
    if (s != nullptr)
    {
        val = s->value;
        s = s->next;
    }
    return val;
}

int main()
{
    int row_1[4];
    int row_2[4];
    int row_3[4];
    int row_4[4];
    for (int i = 0; i < 4; i++)
    {
        // cin >> row_1[i] >> row_2[i] >> row_3[i] >> row_4[i];
    }
}
