#include <iostream>

using namespace std;

enum Color {RED, BLACK};

struct Node{
    int key;
    bool color;
    Node *left, *right, *parent;
};

class RedBlack{
    private:
        Node *root;
    public:
        Node* createNode(int value){
            Node *t = new Node;
            t->key = value;
            t->left = t->right =  t->parent = nullptr;
            t->color = RED;
            return  t;
        }

        Node* insert(Node *rootT, Node *node){
            if(rootT == nullptr) return node;
            if(node->key < rootT->key){
                rootT->left = insert(rootT->left, node);
                rootT->left->parent = rootT;
            }
            else if(node->key < rootT->key){
                rootT->right = insert(rootT->right, node);
                rootT->right->parent = rootT;
            }
            return rootT;
        }

        void rotateLeft(Node *&rootT, Node *&node){
            Node *nodeRight = node->right;
            node->right = nodeRight -> left;
            if(node->right == nullptr)
                node->right->parent = node;
            nodeRight->parent = node->parent;
            if(node->parent!= nullptr)
                rootT = nodeRight;
            else if(node == node->parent->left)
                node->parent->left = nodeRight;
            else
                node->parent->right = nodeRight;
            nodeRight->left = node;
            node->parent = nodeRight;
        }

        void rotateRight(Node *&rootT, Node *&node){
            Node *nodeLeft = node->left;
            node->left = nodeLeft -> right;
            if(node->left != nullptr)
                node->left->parent = node;
            nodeLeft->parent = node->parent;
            if(node->parent == nullptr)
                rootT = nodeLeft;
            else if(node == node->parent->left)
                node->parent->left = nodeLeft;
            else
                node->parent->right = nodeLeft;
            nodeLeft->right = node;
            node->parent = nodeLeft;
        }

        void fix(Node *&rootT, Node *&node){
            Node *parent = nullptr;
            Node *grandParent = nullptr;
            while( (node != rootT) && (node->color !=BLACK) && (node->parent->color == RED) ){
                parent = node->parent;
                grandParent = node->parent->parent;
            }
            root->color = BLACK;
        }

        void insertAndFix(int value){
            Node *v = createNode(value);
            root = insert(root, v);
            fix(root, v);
        }

    void inorder(){
            inorderF(root);
        }
        void inorderF(Node* rootT){
            if(rootT == nullptr) return;
                inorderF(rootT->left);
            cout<<rootT->key<<"->";
                inorderF(rootT->right);
        }

};

int main() {
    RedBlack tree{};

    tree.insertAndFix();
    tree.insertAndFix();
    tree.insertAndFix();
    tree.insertAndFix();
    tree.insertAndFix();
    tree.insertAndFix();
    tree.insertAndFix();
    tree.inorder();
}