#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    
};

struct node *head=NULL;
int numberoflinks = 0;


void insert (int data, int p); // insert: insert number (x) at position (y)
                                 // given in main (x ,y)
void print (struct node *tempprint); // print full list
int count (struct node* temp); //count number of links
void prof (struct node* temp, int p); //count steps from head to link

int main()
{
    head=NULL;
    
    insert(1,1);
    insert(2,2);
    insert(1,1);
    insert(1,1);
    insert(2,2);
    insert(1,1);

    struct node *tempprint = head;
    print(tempprint);
    printf("\n");
    count(head);
    printf("number of links: %d\n", numberoflinks);
    int llistsize = numberoflinks;
    prof(head, 4);
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

int count (struct node* temp)
{
    
    
    if (temp == NULL)
    {
        return numberoflinks;
    }
    else
    {
        numberoflinks++;
        temp = temp->next;
        count (temp);
        return numberoflinks;
    }
    
}

void prof (struct node* temp, int p)
{
    if (temp != NULL && p > 1)
    {
        
        int j = 0;
        for (j = 0; j < p -1 ; j++)       
        {
             temp = temp->next;
        
        }
        
    printf("steps from head: %d", j);
    printf("\n");
        
    }
    
    else
    printf("at head\n");
    
}