/*Find the kth smallest and kth largest number in a binary search tree*/
#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node *right;
	struct Node *left;
	Node(int n){
		this->data = n;
		right=left=NULL;
		}
	};
	
struct Node *kthsmallest(struct Node *root,int count, int k){
	if(root==NULL){
		return NULL;
		}
	struct Node *left = kthsmallest(root->left,count,k);
	if(left!=NULL)
	{
	return left;
	}
	++count;
	if(count==k){
		return root;
		}
	return kthsmallest(root->right,count,k);
	}
void kthlargest(struct Node *root,int count, int k){
	if(root==NULL){
		return;
		}
	kthlargest(root->right,count,k);
	count++;
	if(count==k){
		cout<<root->data;
		}
	kthlargest(root->left,count,k);
	}
void printsmallest(struct Node *root, int k){
	int count = 0;
	struct Node* res = kthsmallest(root,count,k);
	if(res!=NULL){
		cout<<res->data;
		}else{
			cout<<"Not enough Nodes";
			}
	}	
void printlargest(struct Node *root, int k){
	int count = 0;
	kthlargest(root,count,k);
	
	}	
struct Node* insert(Node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return new Node(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
int main(){
	struct Node* root = NULL; 
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 }; 
  
    for (int x : keys) 
        root = insert(root, x); 
  
    int k = 3; 
    printsmallest(root,k);
    cout<<"\nkth Largest\n";
    struct Node *root2 = NULL; 
    root = insert(root2, 50); 
    insert(root2, 30); 
    insert(root2, 20); 
    insert(root2, 40); 
    insert(root2, 70); 
    insert(root2, 60); 
    insert(root2, 80); 
  
   
    for (int c=1; c<=7; c++){ 
        printlargest(root,c); 
    }
    
	
	}
