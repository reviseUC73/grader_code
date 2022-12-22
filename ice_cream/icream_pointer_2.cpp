#include <iostream>
using namespace std;
struct ListNode
{
    typedef int valueType;
    valueType val;
    ListNode *next;
    // ListNode *prev;
    ListNode(valueType val, ListNode *next = NULL)
        : val(val), next(next) {}

    // ListNode(valueType val, ListNode *next = 0, ListNode *prev = 0)

    //     : val(val), next(next), prev(prev) {}
};

int q_out[100000];
int main()
{
    int r=0;
    int new_pos = 0;
    ListNode *header = new ListNode(0);
    ListNode *last;
    last = header;
    cin >> r;
    int num = 0;
    for (int i = 0; i < r; i++)
    {
        int command = 0, count_user = 0, id = 0;
        cin >> command;
        if (command == 1) // add
        {
            cin >> count_user;
            for (int j = 0; j < count_user; j++)
            {
                cin >> id;
                ListNode *user = new ListNode(id);
                last->next = user;
                last = user; // tell "last is last index"(update las)
                // in_q->next = id;
                num++;
            
            }
        }
        else if (command == 2) // out
        {
            if (header->next != NULL)
            {
                // q_out[new_pos] = header->next->val;
                // new_pos++;
                // cout<<"["<<header->val<<"]"<<endl;
                // cout<<"["<<header->next->val<<"]"<<endl;
                cout<<header->next->val<<endl;
                // ListNode *new_next_h = header->next;
                delete header->next;
                header->next = header->next->next; // blue
                num--;
            }
        }
    }
    // for (int i = 0; i < new_pos; i++)
    // {
    //     cout << q_out[i] << endl;
    // }

    // int num = 0;
    // while (header->next != NULL)
    // {
    //     header = header->next;
    //     num++;
    // }
    cout << num;
}
