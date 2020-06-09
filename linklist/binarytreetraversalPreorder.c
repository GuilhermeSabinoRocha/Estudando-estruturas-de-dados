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
queu* level = NULL;
node* insert (node* asd, int data);
void push (node* root);
void preorder(node* root);

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
    preorder(root);


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

//  enqueue a node by means of 'queu pessoa'
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
/* print node then go left the go right. This function can be 
Inorder and Postorder too, by changing order of lines 93, 94, and 95 */

void preorder(node* root)

{
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);    
}

bool isbst(node* root)
{
    
}