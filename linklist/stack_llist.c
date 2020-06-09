#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node *head = NULL;
void push(int a);
void pop();
void top();
void print();


int main()
{
    head = NULL;
    push(1);
    push(2);
    push(2);
    print();
    pop();
    print();
}


void push(int a)
{
    node* temp2 = (node*)malloc(sizeof(node));
    
    temp2->data = a;
    temp2->next = head;
    head = temp2;
}

void pop()
{
    node* temp;
    if (head == NULL) {return;}
    temp = head;
    head = head->next;
    free(temp);
}

void print()
{
    node* temp = head;
    while (temp !=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}