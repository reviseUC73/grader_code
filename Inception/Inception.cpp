#include <iostream>

using namespace std;
typedef string ValueType;
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
        n->next = rear;
        rear = n;
    }
    else
    {
        front = rear = n;
    }
}

void extract(ListNode *&front, ListNode *&rear)
{
    ListNode *new_rear = rear->next;
    delete rear;
    rear = new_rear;
}

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char cmd[10];
        cin >> cmd;

        if (cmd[0] == 'S')
        {

            string text;
            cin >> text;

            append(front,rear, text);
        }
        else if (cmd[0] == 'K')
        {
            if (rear != nullptr)
            {
                extract(front,rear);
            }
        }
        else
        {
            if (rear != nullptr)
            {
                cout << rear->val << endl;
            }
            else
            {
                cout << "Not in a dream" << endl;
            }
        }
    }
}