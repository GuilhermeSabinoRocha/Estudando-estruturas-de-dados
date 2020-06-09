#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

node* insert (node* asd, int data);
void print(node* b);
bool search (node * asd, int data);
int max (int l, int r);
int FindHeight(node* root);

int main()
{
    node *root = NULL;

    root =insert(root, 10);
    root =insert(root, 5);
    root =insert(root, 4);
    root =insert(root, 6);
    root =insert(root, 60);
    root =insert(root, 100);
    print(root);
    if (search (root, 100)== true)
    {printf("true\n");}
    else {printf("false\n");}
    printf("%d\n", FindHeight(root));
    

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

/* searches for a number and returns true if it exists in tree, and false if it does not  */
bool search (node * asd, int data)
{
    if (asd == NULL) {return false;}

    else if (asd->data == data) 
    {
        return true;
    }
    else if (data <= asd->data) 
    {
               
        return search(asd->left, data);
    }
    else 
    {
               
        return search(asd->right, data);
    }
    
    
}

int findmin(node* root)
{
    if (root ==NULL) return -1;
    else if (root->left == NULL)
    {
        return root->data;
    }
    else
    {
        return findmin(root->left);
    }
    

}

int max (int l, int r)
{
    if (l > r)
    {
        return l;
    }
    else
    {
        return r;
    }
    
    
}
//recursively finds the height of tree, from a given node till the farthest node
int FindHeight(node* root)
{
    if(root == NULL) return -1;
    
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}