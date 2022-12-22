#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
    int size;
} stack;

void push(stack *s, int v)
{
    node *this_push = new node();
    this_push->next = nullptr;
    this_push->value = v;
    if (s->top == nullptr)
    {
        s->top = this_push;
    }
    else
    {
        this_push->next = s->top;
        s->top = this_push;
    }
    s->size += 1;
}

int is_stack_empty(stack *s)
{
    if (s->size <= 0)
    {
        return 1;
    }
    return 0;
}

int pop(stack *s)
{
    if (s->top != nullptr)
    {
        int out = s->top->value;
        s->top = s->top->next;
        s->size -= 1;
        return out;
    }
}
void print_yo(stack *s)
{
    cout << "-----Top-----" << endl;
    stack *temp = s;
    node *yo = temp->top;
    int size = temp->size;
    while (yo != nullptr)
    {
        // cout << temp->top->value << " -- <" << temp->size << ">" << endl;
        // cout << s->top->value << " -- <" << s->size << ">" << endl;
        // cout << temp->top->value << " -- <" << temp->size << ">" << endl;
        cout << yo->value << " -- <" << size << ">" << endl;
        size -= 1;
        yo = yo->next;
    }
    cout << "-----Under-----" << endl;
}

int main()
{
    stack top = {NULL, 0};
    int op, v;
    while (true)
    {
        printf("Menu : ");
        scanf("%d", &op);
        if (op == 0)
        {
            scanf("%d", &v);
            push(&top, v);
        }
        else if (op == 1)
        {
            if (is_stack_empty(&top) == 1)
                printf("Stack is already empty!!!\n");
            else
                printf("%d\n", pop(&top));
        }
        else if (op == 3)
        {
            print_yo(&top);
        }

        else
        {
            printf("END CODE\n");
            break;
        }
    }
    return 0;
}