/**
	Fenwick tree or Binary Indexed Tree (BIT) using STL
 */
#include<iostream>
#include<vector>

using namespace std;


int getSum(vector<int> &BITree, int index){
	int sum = 0;
	index+=1;
	while(index > 0){
		sum+=BITree[index];
		index = index - (index&(-index));
	}
	return sum;
}

void updateBIT(vector<int> &BITree, int index, int val){
	index+=1;
	while(index < BITree.size()) {
		BITree[index]+=val;
		index = index + (index & (-index));
	}
}

vector<int> construct(vector<int> &arr){
	std::vector<int> BITree = std::vector<int>(arr.size()+1, 0);

	for(int i = 0; i < arr.size(); i++ ) {
		updateBIT(BITree, i, arr[i]);
	}

	return BITree;
}

int main() {

	int n;
	cin>>n;
	std::vector<int> arr(n);
	for(int i = 0 ; i < n; i++ ) {
		cin>>arr[i];
	}
	std::vector<int> BITree = construct(arr);
	int queryIndex;
	cin>>queryIndex;
	cout<<getSum(BITree, queryIndex);

	return 0;
}
