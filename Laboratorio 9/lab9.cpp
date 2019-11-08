#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d \n", root->key);
        inOrder(root->right);
    }
}

void preOrder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d \n", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

struct node *insert(struct node *node, int key)
{

    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

void postOrder(struct node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);

    postOrder(root->right);

    printf("%d \n", root->key);
}

struct node *ancestro(struct node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->key > n1 && root->key > n2)
    {
        return ancestro(root->left, n1, n2);
    }

    if (root->key < n1 && root->key < n2)
    {
        return ancestro(root->right, n1, n2);
    }

    return root;
}
int distFromAncestor(struct node *root, int k, int cont)
	{
	    if(root->key == k)
            return cont;
        if(root->key > k)
            cont =distFromAncestor(root->left,k,cont+1);
        if(root->key < k)
            cont =distFromAncestor(root->right,k,cont+1);
        return cont;
	}
	
int distancia(struct node *root,int a, int b){
    return distFromAncestor(root,a,0) + distFromAncestor(root,b,0);
}



struct node *deleteNode(struct node *root, int key)
{

    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key); 
    else
    {

        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = minValueNode(root->right);

        root->key = temp->key; 
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main()
{
    /* Let us create following BST50/ \30 70/ \ / \20 40 60 80 */
    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);


    //Ejercicio 1
    cout<<ancestro(root,1,13) ->key;
    printf(" \n");
    //Ejercicio 2
    cout<<distancia(ancestro(root,1,7),1,7);
    return 0;
}