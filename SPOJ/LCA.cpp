#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int getLCA(/*vector<vector<int> > &tree,*/ vector<int> &parent, int &l, int &r){
	std::vector<int> lpath, rpath;
	while(l >= 1) {
		lpath.push_back(l);
		l = parent[l];
	}
	while(r >= 1) {
		rpath.push_back(r);
		r = parent[r];
	}
	// cout<<lpath.size()<<", "<< rpath.size()<<endl;
	int i,j;
	for(i = lpath.size()-1, j = rpath.size()-1; i >=0 && j >= 0; i--, j--){
		if(lpath[i] != rpath[j]){
			//return lpath[i+1];
			break;
		}
	}
	return lpath[i+1];
}

int main() {
	int t;
	cin>>t;
	int n, ni, temp, q, l,r;
	for(int ti = 0; ti < t; ti++) {

		cin>>n;
		// vector<vector<int> > tree(n+1);//, new std::vector<int>());
		vector<int> parent(n+1, 0);
		for(int i = 0; i < n; i++) {
			cin>>ni;
			while(ni--){
				cin>>temp;
				// tree[i+1].push_back(temp);
				parent[temp] = i+1;
			}	
		}
		// cout<<endl;
		// for(int i = 0; i <= n; i++) {
		// 	cout<<"("<<i<<","<<parent[i]<<"),";
		// }
		// cout<<endl;
		cin>>q;
		printf("Case %d:\n", (ti+1));
		// cout<<"Case "<<ti+1<<":"<<endl;
		for(int _ = 0; _ < q; _++) {
			cin>>l>>r;
			// cout<<getLCA(parent, l,r);
			printf("%d\n", getLCA(parent, l,r));
			// cout<<endl;
		}

		
	}
	return 0;
}