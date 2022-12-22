#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef struct queue
{
    node *front;
    node *rear;
    int size;
} queue;

void enqueue(queue *q, int v)
{
    node *new_queue = new node;
    new_queue->value = v;
    new_queue->next = nullptr;

    node *temp_lst = q->front;
    if (q->front == nullptr)
    {
        q->front = q->rear = new_queue;
    }
    else
    {
        while (temp_lst->next != nullptr)
        {
            temp_lst = temp_lst->next;
        }
        temp_lst->next = new_queue;
        q->rear = new_queue;
    }
    q->size += 1;
}

int is_queue_empty(queue *q)
{
    if(q->size<=0){
        return 1;
    }
    return 0;
}

int dequeue(queue *q)
{
    int num = 0;
    if (q->front != nullptr)
    {
        q->size -= 1;
        num = q->front->value;
        if (q->front->next != nullptr)
        {
            // delete q->front;
            q->front = q->front->next;
        }
        else
        {
            q->front = q->rear = nullptr;
        }
        return num;
    }
    return num;
}

int main()
{
    queue Q = {NULL, NULL, 0};
    int op, v;
    while (true)
    {
        printf("Menu : ");
        scanf("%d", &op);
        if (op == 0)
        {
            scanf("%d", &v);
            enqueue(&Q, v);
        }
        else if (op == 1)
        {
            if (is_queue_empty(&Q) == 1)
                printf("Queue is already empty!!!\n");
            else
                printf("%d\n", dequeue(&Q));
        }
        else
        {
            printf("END CODE\n");
            break;
        }
    }
    return 0;
}
