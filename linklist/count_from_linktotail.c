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
void altura (struct node* temp, int p, int size); //count steps from link till tail

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
    altura(head, 1, llistsize);
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

void altura (struct node* temp, int p, int size)
{
    if (temp != NULL && size > 1)
    {
        int i = 0;
        while (temp->next != NULL && i < p -1)       
        {
            temp = temp->next;
            i++;
            
        }
        
        int j;
        for (j = 0; temp->next != NULL; j++)       
        {
             temp = temp->next;
        
        }
        
    printf("steps to tail: %d", j);
    printf("\n");
        
    }
    
    
    
}