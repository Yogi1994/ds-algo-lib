/*
https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0/
*/
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t; 
	while(t--){
	    char a[1000], b[1000];
	    cin>>a>>b;
	    int m, n;
	    for( int i =0; a[i]!='\0'; i++) {
	        m = i+1;
	    }
	    for( int i =0; b[i]!='\0'; i++) {
	        n = i+1;
	    }
	    int dp[m+1][n+1];
	    for(int i =0 ; i <= m; i++) {
	        for( int j = 0; j <=n; j++) {
	            if(i ==0|| j == 0){
	                dp[i][j] = 0;
	            } else if(a[i-1] == b[j-1]){
	                dp[i][j] = dp[i-1][j-1]+1;
	            } else {
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	            }
	        }
	    }
	    cout<<n+m -dp[m][n]<<endl;
	    
	}
	return 0;
}