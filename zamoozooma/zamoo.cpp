#include <iostream>
using namespace std;
typedef struct node
{
    int value;
    struct node *next;
    node(int v = 0, node *nxt = nullptr)
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

void push(node *&s, int v) // front
{
    node *this_push = new node(v);
    // this_push->next = nullptr;
    // this_push->value = v;
    if (s != nullptr)
    {
        this_push->next = s;
    }

    s = this_push;
}
void append(node *&s, int v) // back
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
bool check_repeat(node *&s, int num)
{
    node *temp = s;
    if (temp->next == nullptr and num == temp->value)
        return true;

    while (temp->next->next != nullptr)
    {
        if (temp->value == num)
        {
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    return false;
}
int main()
{
    int box[1000];
    int n = 0;
    cin >> n;
    int count = 0;
    int cmd;
    node *lst = nullptr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> cmd;
        cin >> a;
        //
        // if (cmd == 0)
        // {
        //     push(lst, a);
        //     count += 1;
        //     box[i] = a;
        // }
        // else
        // {
        //     append(lst, a);
        //     count += 1;
        //     box[i] = a;
        // }
        // int yo = 0;
        // for (int j = 0; j < i; j++)
        // {
        //     if (box[yo] == a)
        //     {
        //         lst = nullptr;
        //         if (count != 0)
        //         {
        //             count = 1;
        //         }
        //         else
        //         {
        //             count = 0;
        //         }
        //     }
        //     else
        //     {
        //         yo++;
        //     }
        // }
        
        if (cmd == 0)
        {
            push(lst, a);
            count += 1;
            box[i] = a;
        }
        else
        {
            append(lst, a);
            count += 1;
            box[i] = a;
        }
        print_lst(lst);
    }
    cout << count;
}