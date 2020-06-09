#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
    
}node;

 node *head = NULL;


void insert(int data, int p);
void print();
void release();


int main()
{
    head = NULL;
    insert(1,1);
    insert(1,1);
    insert(1,1);
    insert(1,1);
    insert(4,4);
    print();
    release();
    
}

void insert(int d, int p)
{
     node *temp = malloc(sizeof( node));
    (*temp).data = d;
    temp->next = NULL;
    
    if (p ==1)
    {
        temp->next = head;
        head = temp;
        return;
    }

     node* temp2 = head;
    int i;
    for (i=0; i < p-2; i++)
    {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
        
 
}


void print()
{
     node* temp2 = head;
    while (temp2 != NULL)
    {
        printf("%d\n", temp2->data);
        temp2 = temp2->next;
    }
}

void release()
{
    node *temp = head;
    node *prox = NULL;
    for(; temp != NULL; temp = prox)
    {
        prox = temp->next;
        free(temp);
    }
    
    
    
}

