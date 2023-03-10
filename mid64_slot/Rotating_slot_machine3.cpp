#include <iostream>
using namespace std;
int max_point = 0;
typedef struct node
{
    int value;
    struct node *next;
    node(int v = 0, node *nxt = 0)
        : value(v), next(nxt) {}
} node;

// void print_lst(node *s)
// {
//     int i = 0;
//     while (s != NULL)
//     {
//         printf("(%d)-%d ", i, s->value);
//         s = s->next;
//         i++;
//     }
//     printf("\n");
// }
void print_all_rows(node *row_1, node *row_2, node *row_3, node *row_4)
{
    for (size_t i = 0; i < 4; i++)
    {

        cout << row_1->value << " " << row_2->value << " " << row_3->value << " " << row_4->value << endl;
        if (i < 3)
        {
            row_1 = row_1->next;
            row_2 = row_2->next;
            row_3 = row_3->next;
            row_4 = row_4->next;
        }
    }
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
void cir_link(node *&s)
{
    node *temp = s;
    node *header = s;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = header;
}

void current_point(node *row_1, node *row_2, node *row_3, node *row_4)
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        int val = row_1->value;
        if (row_1->value == val and row_2->value == val and row_3->value == val and row_4->value == val)
        {
            count += 1;
        }
        row_1 = row_1->next;
        row_2 = row_2->next;
        row_3 = row_3->next;
        row_4 = row_4->next;
    }
    if (max_point < count)
        {
            max_point = count;
        }
    // return count;
}

void spin_point(node *row_1, node *row_2, node *row_3, node *row_4)
{
    for (int i = 0; i < 4; i++)
    {
        int val = row_1->value;

        int count = 0;

        row_1 = row_1->next;
        for (int a = 0; a < 4; a++)
        {
            row_2 = row_2->next;
            for (int b = 0; b < 4; b++)
            {
                row_3 = row_3->next;
                for (int c = 0; c < 4; c++)
                {
                    row_4 = row_4->next;
                        // cout << endl;
                        // cout << "== " << i + 1 << " ==" << endl;
                        // print_all_rows(row_1, row_2, row_3, row_4);
                        // cout << "== " << i + 1 << " ==" << endl;
                        // cout << endl;
                        current_point(row_1, row_2, row_3, row_4);
                    
                }
            }
        }
    }
}

int main()
{
    node *row_1 = nullptr;
    node *row_2 = nullptr;
    node *row_3 = nullptr;
    node *row_4 = nullptr;
    for (int i = 0; i < 4; i++)
    {
        // cout << "yo" << endl;
        int a = 0, b = 0, c = 0, d = 0;
        cin >> a;
        cin >> b;
        cin >> c;
        cin >> d;
        // cin >>a;
        // cout << "yo1" << endl;
        append(row_1, a);
        append(row_2, b);
        append(row_3, c);
        append(row_4, d);
        // cout << "yo3" << endl;
    }
    // cout << "yo4" << endl;
    cir_link(row_1);
    cir_link(row_2);
    cir_link(row_3);
    cir_link(row_4);
    spin_point(row_1, row_2, row_3, row_4);
    cout << max_point;
}
