#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
    
};

struct node *head;

struct node* getnewnode (int x);
void insertathead (int x);
void print();
void reverseprint();
void insertattail (int x);

int main()
{
    head = NULL;
    insertathead(3); print(); reverseprint();
    insertathead(2); print(); reverseprint();
    insertathead(1); print(); reverseprint();
    insertattail(4); print(); reverseprint();
}

struct node* getnewnode (int x)
{
    /*creating node on stack 
    (instead of in heap with malloc)
    
    struct node newnode; 
    newnode.data = x;
    newnode.prev = NULL;
    newnode.next = NULL;
    
    return &newnode;
    */
    
    
    //below, the proper way to do it
    // node on stack is no more accessible when
    //the stack frame finishes execution
    
    
    struct node* newnode 
            = (struct node*)malloc(sizeof(struct node));
    
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = NULL;
    
    return newnode;
    free(newnode);
}

void insertathead (int x)
{
    struct node *newnode = getnewnode(x);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    
    head->prev = newnode;    
    newnode->next = head;    
    head = newnode;    
}

void print()
{
    struct node *temp = head;
    
    printf("Forward: ");
    
    while (temp != NULL) //experimentar com temp->next
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseprint()
{
    struct node *temp = head;
    
    if (temp == NULL) return;
    
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Reverse: ");
    
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void insertattail (int x)
{
    struct node *newnode = getnewnode(x);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;    
    newnode->prev = temp;
    
}
