// #include <iostream>

// using namespace std;

// typedef struct node
// {
//     int value;
//     struct node *next;
//     node(int v = 0, node *nxt = 0)
//         : value(v), next(nxt) {}
// } node;

// void push(node *&s, int v)
// {
//     node *this_push = new node();
//     this_push->next = nullptr;
//     this_push->value = v;
//     if (s != nullptr)
//     {
//         this_push->next = s;
//     }
//     s = this_push;
// }

// int pop(node *&s)
// {
//     int val = 0;
//     if (s != nullptr)
//     {
//         val = s->value;
//         s = s->next;
//     }
//     return val;
// }
// bool check_repeat(node *&s, int num)
// {
//     node *temp = s;
//     int value = s->value;
//     for (int i = 0; i < num; i++)
//     {
//         if (temp == nullptr or temp->value != value)
//         {
//             return false;
//         }
//         temp = temp->next;
//     }
//     return true;
// }
// int main()
// {
//     int n = 0, k = 0, count = 0;
//     cin >> n;
//     cin >> k;
//     node *lst = nullptr;

//     for (int i = 0; i < n; i++)
//     {
//         int put = 0;
//         cin >> put;
//         push(lst, put);
//         if (check_repeat(lst, k))
//         {
//             // count += 1;
//             for (int j = 0; j < k; j++)
//             {
//                 pop(lst);
//             }
//         }
//     }

//     while (lst != nullptr)
//     {
//         count += 1;
//         lst = lst->next;
//     }
//     cout << count << endl;
// }

#include <iostream>

using namespace std;

typedef struct node
{
    int value;
    struct node *next;
    node(int v = 0, node *nxt = NULL)
        : value(v), next(nxt) {}
} node;

void push(node *&s, int v)
{
    node *this_push = new node(v, s);
    s = this_push;
}

int pop(node *&s)
{
    int val = 0;
    if (s != NULL)
    {
        val = s->value;
        s = s->next;
    }
    return val;
}

bool check_repeat(node *&s, int num)
{
    node *temp = s;
    int value = s->value;
    int count = 0;
    while (temp != NULL and temp->value == value and count < num)
    {
        temp = temp->next;
        count++;
    }
    return count == num;
}

int main()
{
    int n = 0, k = 0;
    cin >> n;
    cin >> k;
    node *lst = NULL;

    for (int i = 0; i < n; i++)
    {
        int put = 0;
        cin >> put;
        push(lst, put);
        if (check_repeat(lst, k))
        {
            for (int j = 0; j < k; j++)
            {
                pop(lst);
            }
        }
    }

    int count = 0;
    while (lst != NULL)
    {
        count += 1;
        lst = lst->next;
    }
    cout << count << endl;
}
