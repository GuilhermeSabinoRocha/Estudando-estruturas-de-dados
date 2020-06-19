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
node* findmin(node* root);
int FindHeight(node* root);
 node* Delete( node *root, int data);

int main()
{
    node *root = NULL;

   	root = insert(root,5); root = insert(root,10);
	root = insert(root,3); root = insert(root,4); 
	root = insert(root,1); root = insert(root,11);
    print(root);
	// Deleting node with value 5, change this value to test other cases
	root = Delete(root,11);
    print(root);

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

node* findmin(node* root)
{
    while(root->left != NULL) root = root->left;
	return root;

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

/* finds and delete a particular node */
 node* Delete( node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			free (root);
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			 node *temp = root;
			root = root->right;
			free (temp);
		}
		else if(root->right == NULL) {
			 node *temp = root;
			root = root->left;
			free (temp);
		}
		// case 3: 2 children
		else { 
			 node *temp = findmin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
 