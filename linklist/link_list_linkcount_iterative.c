#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    
};

struct node *head=NULL;


void insert (int data, int p); // insert: insert number (x) at position (y)
                                 // given in main (x ,y)
void print (struct node *tempprint); // print full list
void count (struct node* head); //count number of links

int main()
{
    head=NULL;
    
    insert(1,1);
    insert(2,2);
    insert(1,1);
    insert(10,3);
    insert(111,4);
    struct node *tempprint = head;
    print(tempprint);
    printf("\n");
    count(head);
}

/*
insert: insert number (x) at position (y)
given in main (x ,y)
*/

void insert (int data, int p)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    
    
    if (p == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }
    
    else
    {
        struct node *temp2 = head;
        
        int i;
        for (i = 0; i < p - 2; i++)
            temp2 = temp2->next;
        
        temp->next = temp2->next;
        temp2->next = temp;
    }
    
}

void print (struct node *tempprint)
{
    if (tempprint == NULL)
    return;
    else
    {
    
    printf("%d ", tempprint->data);
    tempprint = tempprint->next;
    print(tempprint);
    }
}

void count (struct node* head)
{
    struct node *temp = head;
    int i;
    int numberoflinks = 0;
    
    if (temp == NULL)
    {
        printf("list is empty");
        return;
    }
    
    while (temp != NULL)
    {
        numberoflinks++;
        temp = temp->next;
    }
    
    printf("number of links: %d\n", numberoflinks);
    
}