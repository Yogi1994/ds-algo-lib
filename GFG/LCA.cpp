/**

lowest-common-ancestor-binary-tree-
*/

#include<iostream>

using namespace std;


struct Node {
	int data;
	Node* left;
	Node *right;

};
Node* createNewNode(int data) {
	Node *newNode = new Node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}

Node* findLCA(Node* node, int n1, int n2){
	if(node == NULL) {
		return NULL;
	}
	if(node->data == n1 || node->data == n2){
		return node;
	}
	Node* left_lca = findLCA(node->left, n1, n2);
	Node* right_lca = findLCA(node->right, n1, n2);

	if (left_lca && right_lca)  return node;

	return (left_lca == NULL)?right_lca:left_lca;
}

int main() {

	/**
			 1
		   /   \
		  2     3
		 / \   / \
		4   5  6  7
		
	**/
	Node * root = createNewNode(1);
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(6);
    root->right->right = createNewNode(7);
    cout << "LCA(4, 6) = " << findLCA(root, 4, 6)->data;
    cout << "\nLCA(7, 6) = " << findLCA(root, 7, 6)->data;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->data;
    cout << "\nLCA(2, 3) = " << findLCA(root, 2, 3)->data;



	return 0;
}