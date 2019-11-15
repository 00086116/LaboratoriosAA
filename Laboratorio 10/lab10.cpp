#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    Node* left,  *right; 
}; 
  

void guardarNodosBST(Node* root, vector<Node*> &nodes) 
{ 

    if (root==NULL) 
        return; 
  

    guardarNodosBST(root->left, nodes); 
    nodes.push_back(root); 
    guardarNodosBST(root->right, nodes); 
} 
  

Node* balancear(vector<Node*> &nodes, int start, int end) 
{ 
    if (start > end) 
        return NULL; 
  
    int mid = (start + end)/2; 
    Node *root = nodes[mid]; 

    root->left  = balancear(nodes, start, mid-1); 
    root->right = balancear(nodes, mid+1, end); 
  
    return root; 
} 
  

Node* construirArbol(Node* root) 
{ 

    vector<Node *> nodes; 
    guardarNodosBST(root, nodes); 
  
    int n = nodes.size(); 
    return balancear(nodes, 0, n-1); 
} 
  
Node* insert(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
void inOrder(Node* node) 
{ 
    if (node == NULL) 
        return; 
    inOrder(node->left); 
    printf("%d ", node->data); 
    inOrder(node->right); 
} 

void preOrder(Node* node) 
{ 
    if (node == NULL) 
        return; 

    printf("%d ", node->data); 
    preOrder(node->left); 
    preOrder(node->right); 
} 

void postOrder(Node* node) 
{ 
    if (node == NULL) 
        return; 

    postOrder(node->left); 
    postOrder(node->right); 
    printf("%d ", node->data); 
} 
  
int main() 
{ 
    /* Ejemplo de Clase 
                2 
               / \
              1   8  
                 / 
                7 
               / 
              6 
             / 
            5
           / 
          4    
    */
  
    Node* root = insert(2); 
    root->left = insert(1);
    root->right = insert(8); 
    root->right->left = insert(7); 
    root->right->left->left = insert(6); 
    root->right->left->left->left = insert(5); 
    root->right->left->left->left->left = insert(4); 
    root->right->left->left->left->left->left = insert(3); 

    root = construirArbol(root); 
  
    cout<< "Inorder: " << endl; 
    inOrder(root);
    cout << endl; 

    cout<< "Preorder: " << endl; 
    preOrder(root); 
    cout << endl;

    cout<< "Postorder: " << endl; 
    postOrder(root); 
    cout << endl;
  
    return 0; 
}