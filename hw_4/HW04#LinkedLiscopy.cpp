#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct node
{
    int value;
    struct node *next;
} node;

void print_linklist(node *p)
{
    int i = 0;
    while (p != NULL)
    {
        printf("(%d)-%d ", i, p->value);
        p = p->next;
        i++;
    }
    printf("\n");
}

node *add_front(node *p)
{
    int num = 0;
    cin >> num;
    node *temp = new node();
    temp->next = NULL;
    temp->value = num;

    if (p == NULL)
    {
        return temp;
    }
    temp->value = num;
    temp->next = p;
    p = temp;
    return p;
}
node *add_back(node *p)
{
    int num = 0;
    cin >> num;
    node *temp = new node();
    if (p == NULL)
    {
        temp->next = NULL;
        temp->value = num;
        p = temp;

        return p;
    }
    temp->value = num;
    temp->next = p;
    p = temp;
    return p;
}

int len_linklist(node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    node *temp = new node();
    temp->next = p;
    temp->value = 0;
    int count = 0;
    while (temp->next != NULL)
    {
        count += 1;
        temp = temp->next;
    }
    delete temp;
    return count;
}

node *delete_index(node *p)

{
    int i = 0, num = 0;
    cin >> num;
    node *temp = p;
    node *pre = NULL;
    while (temp != NULL)
    {
        if (num != 0)
        {
            if (i + 1 == num)
            {
                pre = temp;
                temp = temp->next;
                pre->next = temp->next;
                delete temp;
            }
            else
            {
                temp = temp->next;
            }

            i++;
        }
        else
        {
            p = temp->next;
            return p;
        }
    }
    return p;
}

node *delete_value(node *p)
{
    int i = 0, num = 0;
    cin >> num;
    node *current = nullptr;
    node *pre = p;

    while (pre->value == num)
    {
        if (pre->next != nullptr)
        {
            pre = pre->next;
            p = pre;
        }
        else
        {
            p = nullptr;
            break;
        }
    }
    while (pre->next != nullptr) //  have number of node more than 2 and current
    {
        // if (pre->next == nullptr)
        // {
        //     if (pre->value == num)
        //     {
        //         p = nullptr;
        //     }
        // }
        // else
        {
            current = pre->next;       // set new current
            if (current->value == num) // find value and delete
            {
                pre->next = current->next;
            }
            else if (pre->value == num)
            {
                pre = pre->next;
                p = pre;
            }

            else
            {
                pre = pre->next;
            }
        }
    }
    return p;
}

int main()
{
    node *head = NULL;
    int op;
    while (true)
    {
        printf("Menu : ");
        cin >> op;
        // cout << "yo";
        if (op == 0)
        {
            print_linklist(head);
        }
        else if (op == 1)
        {
            head = add_front(head);
        }
        else if (op == 2)
        {
            head = add_back(head);
        }
        else if (op == 3)
        {
            printf("len = %d\n", len_linklist(head));
        }
        else if (op == 4)
        {
            head = delete_index(head);
        }
        else if (op == 5)
        {
            head = delete_value(head);
        }
        else
        {
            printf("END CODE\n");
            break;
        }
    }
    return 0;
}
