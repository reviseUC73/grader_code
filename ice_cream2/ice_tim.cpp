#include <iostream>
using namespace std;

typedef int ValueType;
struct ListNode
{
    ValueType val;
    ListNode *next;
    int fav;

    ListNode(ValueType v, ListNode *nxt = 0, int fav = 0)
        : val(v), next(nxt), fav(fav) {}
};

ListNode *front = nullptr;
ListNode *rear = nullptr;
void append(ListNode *&front, ListNode *&rear, ValueType x)
{   
    int flv = 0;
    cin >> flv;
    ListNode *n = new ListNode(x);
    n->fav = flv;
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
    int flavor[20] = {};
    int m;
    int count = 0;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int n;
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                int user = 0;
                cin >> user;  
                append(front, rear, user);
                // flavor[you_f-1] +=1;
            }
        }
        else
        {
            int user_out = 0;
            flavor[front->fav - 1] += 1;
            user_out = extract(front, rear);
            cout << user_out << endl;
        }
    }
    while (front)
    {
        front = front->next;
        count++;
    }

    cout << count << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << flavor[i] << " ";
    }
}