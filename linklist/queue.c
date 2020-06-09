#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data; 
    struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void enqueue (int x);
void dequeue();
void print();


int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    print();
}

void enqueue (int x)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;

    if (front == NULL && rear == NULL )
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;

}

void dequeue()
{
    if (front == NULL)
    {
        return;
    }    
    node *temp = front;
    front = temp->next;
    free(temp);


}

void print()
{
    if (front == NULL)
    {
        return;
    }
    while (front !=NULL && rear !=NULL)
    {   printf("%d\n",front->data);
        front = front->next;
    }

    
}