#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>

struct node{
    int data;
    struct node* next;
};

struct node* head;

void Insert(int data, int n);
void print();
void delete();



int main()
{
    head=NULL;
    Insert(1,1);
    Insert(2,2);
    Insert(3,3);
    Insert(4,4);
    print();
    int n;
    printf("enter position to delete:");
    scanf("%d",&n);
    delete(n);
    print();


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

    for (int i = 0; i < n-2; i++){
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

void delete(int n)
{

    struct node* temp1 = head; //temp var to access beginning of list

    if (n==1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }


    for (int i = 0; i < n-2; i++){
        temp1 = temp1->next; //access n-1th node
    }

    struct node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free (temp2);
}