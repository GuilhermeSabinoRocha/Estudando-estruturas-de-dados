#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

typedef struct queu
{
    struct node* node;
    struct queu* next;
}queu;

queu* front = NULL;
queu* rear = NULL;
node* insert (node* asd, int data);
void print(node* b);
void push (node* root);
void levelorder (node* root);

int main()
{
    node *root = NULL;

    root =insert(root, 10);
    root =insert(root, 4);
    root =insert(root, 3);
    root =insert(root, 33);
    root =insert(root, 5);
    root =insert(root, 60);
    root =insert(root, 100);
    levelorder(root);
    

}

/* funcnewnode creates a node, a leaf in the tree, to be used in the insert function */
node *funcnewnode (int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

/* finds the right position for a number to be inserted at the tree  */
node* insert (node* asd, int data)
{
    if (asd == NULL)
    {
        asd = funcnewnode(data);
    }
    else if (data <= asd->data)
    {
        asd->left = insert(asd->left, data);
    }
    else
    {
        asd->right = insert(asd->right,data);
    }
    return asd;

}
/* starting from root, prints all numbers to the right */
void print(node* b)
{
    node *a = b;
    while (a != NULL)
    {
        printf("%d\n", a->data);
        a = a->right;
    }

}

void push (node* root)
{
    queu* pessoa = (queu*)malloc(sizeof(queu));
    pessoa->node = root;
    pessoa->next = NULL;


    if (front == NULL && rear == NULL )
    {
        front = rear = pessoa;
        return;
    }
    rear->next = pessoa;
    rear = pessoa;

}

void levelorder (node* root)
{
    if (root ==NULL) return;
    (*push)(root);
    while (front != NULL)
    {
        node* current = front->node;
        printf("%d ", current->data);
        if (current->left !=NULL) (*push)(current->left);
        if (current->right !=NULL) (*push)(current->right);
        front = front->next;
    }
    printf("\n");
}