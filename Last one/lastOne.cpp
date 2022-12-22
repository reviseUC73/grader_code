#include <iostream>
using namespace std;

struct ListNode
{

    ListNode *next;
    int val;
    ListNode(int val, ListNode *next = nullptr)
        : val(val), next(next) {}
};

ListNode *create_cir(int size)
{
    ListNode *header = new ListNode(1);
    ListNode *last = header;
    for (int i = 2; i <= size; i++)
    {
        ListNode *temp = new ListNode(i);
        last->next = temp;
        last = temp;
    }
    last->next = header;
    return header;
}

int main()
{
    ListNode *yo = create_cir(5);
    // for (int i = 0; i < 15; i++)
    // {
    //     cout << yo->val << "-->";
    //     yo = yo->next;
    // }
}