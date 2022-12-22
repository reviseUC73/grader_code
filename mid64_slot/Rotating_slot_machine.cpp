#include <iostream>
using namespace std;
typedef struct node
{
    int value;
    struct node *next;
    node(int v = 0, node *nxt = 0)
        : value(v), next(nxt) {}
} node;

void print_lst(node *s)
{
    int i = 0;
    while (s != NULL)
    {
        printf("(%d)-%d ", i, s->value);
        s = s->next;
        i++;
    }
    printf("\n");
}

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
void append(node *&s, int v)
{
    node *temp = s;
    node *n = new node(v);
    if (temp == nullptr)
    {
        s = n;
    }
    else
    {
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

int extract_last(node *&s)
{
    node *temp = s;
    while (temp->next->next != nullptr) // (@[0]->[1]->[2]->[3]->[4]@)  ->(in you)[5]---> null(range run loop)
    {
        temp = temp->next;
    }
    int val = temp->next->value;
    // delete temp;
    temp->next = nullptr;
    return val;
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
    node *row_1 = nullptr;
    // node *row_2 = new node();
    // node *row_3 = new node();
    // node *row_4 = new node();
    // for (int i = 0; i < 4; i++)
    // {
    //     cin >> row_1->value >> row_2->value >> row_3->value >> row_4->value;
    //     node *row_1_link = new node();
    //     node *row_2_link = new node();
    //     node *row_3_link = new node();
    //     node *row_4_link = new node();
    // }
    append(row_1, 1);
    append(row_1, 2);
    append(row_1, 3);
    append(row_1, 4);
    append(row_1, 5);
    print_lst(row_1);
    cout << extract_last(row_1)<<endl;
    cout << pop(row_1)<<endl;

    // extract_last(row_1);
    // extract_last(row_1);
    print_lst(row_1);
}
