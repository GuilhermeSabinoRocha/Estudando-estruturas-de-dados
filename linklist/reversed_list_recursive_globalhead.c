#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    
};

struct node *head;

void reverse(struct node* p)
{
    
    if (p->next == NULL)
    {
        head = p;
        return ;
    }

    reverse (p->next);
    
    struct node* q = p->next;
    q->next = p;
    p->next = NULL;
}


void Insert(int data, int n)
{
    struct node* temp1 = malloc(sizeof(struct node));
    temp1->data= data;
    temp1->next= NULL;


    if(n==1){
        temp1->next=head;
        head = temp1;

        return;
    }
    struct node* temp2 = head;
    
    int i;
    for (i = 0; i < n-2; i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void print(){
    struct node* temp = head;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head=NULL;
    Insert(1,1);
    Insert(2,2);
    Insert(3,3);
    Insert(4,3);
    print();
    reverse(head);
    print();
}

