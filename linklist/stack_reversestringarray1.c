#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char data;
    struct node* next;
}node;

node* head = NULL;
void push(char* Q, int l);
void insert(char a);
void print();
void reverse(char* Q, int l);
void release();

int main ()
{
    head = NULL;
    printf("input string:");
    char A[50];
    scanf("%s", A);
    push(A, strlen(A));
    print();
    reverse(A, strlen(A));
    printf("\n%s", A);
    release();
}

void push(char* Q, int l)
{
    int i = 0;
    while (i < l)
    {
        insert(Q[i]);        
        i++;

    }

   
}

void insert(char a)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = a;
    temp->next = head;
    head = temp;
}

void print()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%c ", temp->data);
        temp = temp->next;
    }
}

void reverse(char* Q, int l)
{
     int j = 0;
    node *temp2 = head;
    while (j < l)
    {
        Q[j] = temp2->data;
        temp2 = temp2->next;
        j++;
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