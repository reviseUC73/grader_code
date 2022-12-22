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
    int val;
    cin >> val;
    node *temp = new node;
    temp->value = val;
    temp->next = NULL;

    if (p == NULL) 
    {
        p = new node;
    }

    if (p->next == NULL) 
    {
        p->next = temp;
    }
    else
    {
        temp->next = p->next;
        p->next = temp;
    }
    // print_linklist(p);
    return p;
    // node *lst = new node;
    // lst->next = NULL;
    // lst->value = val;

    // if (p->next != NULL) // not first link
    // {
    //     lst->next = p->next; // connect value next of header
    // }
    // p->next = lst; // link header and new value
    // return p;
}
node *add_back(node *p)
{
    
    return p;
}

int len_linklist(node *p)
{
    //////////////////////////////
    ///////// return ??? /////////
    return 0;
}

node *delete_index(node *p)
{
    //////////////////////////////
    ///////// return ??? /////////
    return p;
}

node *delete_value(node *p)
{
    //////////////////////////////
    ///////// return ??? /////////
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