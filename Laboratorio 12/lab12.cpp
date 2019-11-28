#include <iostream> 
#include <queue> 
using namespace std; 

enum colors{ red, black }; 

class Node{ 
public: 
int value; 
colors color; 
Node *left, *right, *p; 

Node(int value):value(value){ 
	p = left = right = NULL;  
	color = red; 
} 

Node *uncle(){ 
	if(p == NULL or p->p == NULL) 
	    return NULL; 
	if(p->isOnLeft()) 
    	return p->p->right; 
	else
    	return p->p->left; 
} 

bool isOnLeft(){ 
	return this == p->left; 
} 

Node *sibling(){ 
	if(p == NULL) 
		return NULL; 
	if(isOnLeft()) 
		return p->right; 
	return p->left; 
} 

void moveDown(Node *nP) { 
	if(p != NULL){ 
		if(isOnLeft()){ 
			p->left = nP; 
		}else{ 
			p->right = nP; 
		} 
	} 
	nP->p = p; 
	p = nP; 
} 

bool hasRedChild(){ 
	return(left != NULL && left->color == red) || (right != NULL && right->color == red); 
    } 
}; 

class RBTree{ 

Node *root; 

void leftRotate(Node *x){ 
	Node *nP = x->right; 
	if(x == root) 
	root = nP; 
	x->moveDown(nP); 
	x->right = nP->left; 
	if(nP->left != NULL) 
	    nP->left->p = x; 
	nP->left = x; 
} 

void rightRotate(Node *x){ 
	Node *nP = x->left; 
	if(x == root) 
	    root = nP; 
	x->moveDown(nP); 
	x->left = nP->right; 
	if(nP->right != NULL) 
	    nP->right->p = x; 
	nP->right = x; 
} 

void swapColors(Node *k1, Node *k2){ 
	colors temp; 
	temp = k1->color; 
	k1->color = k2->color; 
	k2->color = temp; 
} 

void swapValues(Node *u, Node *v){ 
	int temp; 
	temp = u->value; 
	u->value = v->value; 
	v->value = temp; 
} 

void fixRedRed(Node *x){ 
	if(x == root){ 
	    x->color = black; 
	    return; 
	} 

	Node *p = x->p, *granPa = p->p, 
		*uncle = x->uncle(); 

	if(p->color != black){ 
		if(uncle != NULL && uncle->color == red){ 
			p->color = black; 
			uncle->color = black; 
			granPa->color = red; 
			fixRedRed(granPa); 
		}else{ 
			if(p->isOnLeft()){ 
			    if(x->isOnLeft()){ 
				    swapColors(p, granPa); 
			    }else{ 
				    leftRotate(p); 
				    swapColors(x, granPa); 
			    } 
			rightRotate(granPa); 
			}else{ 
			if(x->isOnLeft()){ 
				rightRotate(p); 
				swapColors(x, granPa); 
			}else{ 
				swapColors(p, granPa); 
			} 
			leftRotate(granPa); 
			} 
		} 
	} 
} 
 
Node *successor(Node *x){ 
	Node *temp = x; 
	while(temp->left != NULL) 
	    temp = temp->left; 
	return temp; 
} 

Node *BSTreplace(Node *x){ 
	if(x->left != NULL && x->right != NULL) 
	    return successor(x->right); 
	if(x->left == NULL && x->right == NULL) 
	    return NULL; 
	if(x->left != NULL) 
	    return x->left; 
	else
	    return x->right; 
} 

void deleteNode(Node *v){ 
	Node *u = BSTreplace(v); 
	bool bothBlack = ((u == NULL || u->color == black) && (v->color == black)); 
	Node *p = v->p; 

	if(u == NULL){ 
	if(v == root){ 
		root = NULL; 
	}else{ 
		if(bothBlack){ 
		fixDoubleBlack(v); 
		}else{ 
		    if(v->sibling() != NULL) 
			    v->sibling()->color = red; 
		} 
		if(v->isOnLeft()){ 
		    p->left = NULL; 
		}else{ 
		    p->right = NULL; 
		} 
	} 
	delete v; 
	return; 
	} 
	if(v->left == NULL or v->right == NULL){ 
	if(v == root){ 
		v->value = u->value; 
		v->left = v->right = NULL; 
		delete u; 
	}else{ 
		if(v->isOnLeft()){ 
		    p->left = u; 
		}else{ 
		    p->right = u; 
		} 
		delete v; 
		u->p = p; 
		if(bothBlack){ 
		    fixDoubleBlack(u); 
		}else{ 
		    u->color = black; 
		} 
	} 
	return; 
	} 
	swapValues(u, v); 
	deleteNode(u); 
} 

void fixDoubleBlack(Node *x){ 
	if (x == root)
		return; 

	Node *sibling = x->sibling(), *p = x->p; 
	if(sibling == NULL){ 
	    fixDoubleBlack(p); 
	}else{ 
    	if(sibling->color == red){ 
    		p->color = red; 
    		sibling->color = black; 
    		if(sibling->isOnLeft()){ 
    		    rightRotate(p); 
    		}else{ 
    		    leftRotate(p); 
    		} 
    		fixDoubleBlack(x); 
    	}else{ 
    		if(sibling->hasRedChild()){ 
    		if(sibling->left != NULL && sibling->left->color == red){ 
    			if(sibling->isOnLeft()){ 
        			sibling->left->color = sibling->color; 
        			sibling->color = p->color; 
        			rightRotate(p); 
    			}else{ 
        			sibling->left->color = p->color; 
        			rightRotate(sibling); 
        			leftRotate(p); 
    			} 
    		}else{ 
    			if(sibling->isOnLeft()){ 
        			sibling->right->color = p->color; 
        			leftRotate(sibling); 
        			rightRotate(p); 
    			}else{ 
        			sibling->right->color = sibling->color; 
        			sibling->color = p->color; 
        			leftRotate(p); 
    			} 
    		} 
    		p->color = black; 
    		}else{ 
        		sibling->color = red; 
        		if(p->color == black) 
        			fixDoubleBlack(p); 
        		else
        			p->color = black; 
    		} 
    	} 
    } 
} 

void levelOrder(Node *x){ 
	if (x == NULL) 
    	return; 

	queue<Node *> q; 
	Node *curr; 

	q.push(x); 

	while(!q.empty()){  
    	curr = q.front(); 
    	q.pop(); 
        cout<<curr->value<<" "; 
        if(curr->left != NULL) 
    		q.push(curr->left); 
    	if(curr->right != NULL) 
    		q.push(curr->right); 
    	} 
} 

void inorder(Node *x){ 
	if (x == NULL) 
		return; 
	inorder(x->left); 
	cout<<x->value<<" "; 
	inorder(x->right); 
} 

public: 

RBTree(){ 
	root = NULL; 
} 

Node *getRoot(){ 
	return root; 
} 

Node *search(int n){ 
	Node *temp = root; 
	while(temp != NULL){ 
    	if(n < temp->value){ 
    		if(temp->left == NULL) 
    		    break; 
    		else
    		    temp = temp->left; 
    	}else if(n == temp->value){ 
    		break; 
    	}else{ 
    		if(temp->right == NULL) 
    		    break; 
    		else
    		    temp = temp->right; 
    	} 
	} 

	return temp; 
} 

void insert(int n){ 
	Node *newNode = new Node(n); 
	if(root == NULL){ 
    	newNode->color = black; 
    	root = newNode; 
	}else{ 
	Node *temp = search(n); 
	if(temp->value == n){ 
		return; 
	} 
	newNode->p = temp; 
	if(n < temp->value) 
		temp->left = newNode; 
	else
		temp->right = newNode; 
	fixRedRed(newNode); 
	} 
} 

void deleteByVal(int n){ 
	if(root == NULL){
		return; 
	} 

	Node *v = search(n), *u; 

	if (v->value != n){ 
    	cout<<"No se encontro un nodo con ese valor:"<<n<<endl; 
    	return; 
	} 
	deleteNode(v); 
} 

void printInOrder(){ 
	cout<<"Inorder: "<<endl; 
	if (root == NULL) 
	    cout<<"El arbol esta vacio." <<endl; 
	else
	    inorder(root); 
	cout << endl; 
} 

void printLevelOrder(){ 
	cout<<"Orden del nivel: "<<endl; 
	if (root == NULL) 
	    cout<<"El arbol esta vacio."<<endl; 
	else
	    levelOrder(root); 
	cout<<endl; 
} 

}; 

int main(){ 
    RBTree tree; 
    
    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    
    tree.printInOrder(); 
    tree.printLevelOrder(); 
    
    tree.deleteByVal(4); 
    tree.deleteByVal(3);
    
    tree.printInOrder(); 
    tree.printLevelOrder(); 
    
    return 0; 
} 