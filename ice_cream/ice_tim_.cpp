// #include <iostream>
// using namespace std;

// typedef int ValueType;
// struct ListNode
// {
//     ValueType val;
//     ListNode *next;

//     ListNode(ValueType v, ListNode *nxt = 0)
//         : val(v), next(nxt) {}
// };

// ListNode *front = nullptr;
// ListNode *rear = nullptr;

// void append(ListNode *&front, ListNode *&rear, ValueType x)
// {
//     ListNode *n = new ListNode(x);
//     if (rear != nullptr)
//     {
//         rear->next = n;
//         rear = n;
//     }
//     else
//     {
//         front = rear = n;
//     }
// }

// ValueType extract(ListNode *&front, ListNode *&rear)
// {
//     ValueType v = front->val;

//     ListNode *new_front = front->next;
//     delete front;
//     front = new_front;
//     if (front == nullptr)
//     {
//         rear = nullptr;
//     }
//     return v;
// }

// int main()
// {
//     int m;
//     int count = 0;
//     cin >> m;
//     for (int i = 0; i < m; ++i)
//     {
//         int t;
//         cin >> t;
//         if (t == 1)
//         {
//             int n;
//             cin >> n;
//             for (int j = 0; j < n; j++)
//             {
//                 int user = 0;
//                 cin >> user;
//                 append(front, rear, user);
//             }
//         }
//         else
//         {
//             int user_out = 0;
//             user_out = extract(front, rear);
//             cout << user_out << endl;
//         }
//     }
//     while (front)
//     {
//         front = front->next;
//         count++;
//     }
//     cout << count << endl;
// }

#include <iostream>
using namespace std;

typedef int ValueType;
struct ListNode
{
    ValueType val;
    ListNode *next;

    ListNode(ValueType v, ListNode *nxt = 0)
        : val(v), next(nxt) {}
};

ListNode *front = nullptr;
ListNode *rear = nullptr;

void append(ListNode *&front, ListNode *&rear, ValueType x)
{
    ListNode *n = new ListNode(x);
    if (rear != nullptr)
    {
        rear->next = n;
        rear = n;
    }
    else
    {
        front = rear = n;
    }
}

ValueType extract(ListNode *&front, ListNode *&rear)
{
    ValueType v = front->val;

    ListNode *new_front = front->next;
    delete front;
    front = new_front;
    if (front == nullptr)
    {
        rear = nullptr;
    }
    return v;
}

int main()
{
    int m;
    int x = 0;

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int t;

        cin >> t;
        if (t == 1)
        {
            int count = 0;
            cin >> count;
            for (int j = 0; j < count; j++)
            {
                int n=0;
                cin >> n;
                append(front, rear, n);
            }
        }
        else
        {
            x = extract(front, rear);
            cout << x << endl;
        }
    }

    // you have to print the number of remaining customers as well.
    // iterate the rest of the list here...
}