/**

https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=345&page=show_problem&problem=2683

Finding the maximum XOR sum of subarray.
**/

#include<iostream>

using namespace std;

struct TNode {
	// To store the value at the leaf node.
	int value;
	
	TNode *one;
	TNode *zero;
};

class XORTrie {
	TNode *root;
	int depth;
	TNode* createNode(){
		TNode *_node = new TNode;
		_node->value = 0;
		_node->one = NULL;
		_node->zero = NULL;
		return _node;
	}
	
public:
	XORTrie(){
		this->root = new TNode;
		this->root->value = 0;
		this->root->one = NULL;
		this->root->zero = NULL;
		depth = 20;
		insert(0);
	}
	void insert(int num){
		TNode *node = this->root;
		for( int i = depth-1; i >= 0; i-- ) {
			int bit = (num>>i) & 1;

			if(bit) {
				if(node->one == NULL)
				    node->one = createNode();
				node = node->one;
			} else {
				if(node->zero == NULL)
				    node->zero = createNode();
				node = node->zero;
			}
		}
		node->value = num;
	}
	int queryMax(int prexor) {
		TNode *node = this->root;
		for( int i = depth-1; i >= 0; --i ) {
			int bit = (prexor>>i) & 1;
			if(bit) {
				if(node->zero != NULL){
					node = node->zero;
				} else if(node->one != NULL) {
					node = node->one;
				} 
			} else if(bit ==0 ) {
				if(node->one != NULL){
					node = node->one;
				} else if(node->zero != NULL){
					node = node->zero;
				}	
			} 
		}
		return prexor^node->value;
	}
};


int main() {
	int n;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int prexor = 0;
		int ai;
		XORTrie xorTrie;
		int ans = -100000000;
		for(int i = 0; i < n; i++) {
			cin>>ai;
			prexor = prexor ^ ai;
			xorTrie.insert(prexor);
			ans = max(ans, xorTrie.queryMax(prexor));
		}
		cout<<ans<<endl;

	}

}