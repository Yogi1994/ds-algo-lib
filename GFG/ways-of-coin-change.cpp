/**
https://practice.geeksforgeeks.org/problems/coin-change/0/
**/
#include <iostream>
using namespace std;

int max(int a, int b){
    return (a > b) ? a : b;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i < n; i++) {
	        cin>>arr[i];
	    }
	    int num;
	    cin>>num;
	    int dp[n+1][num+1];
	    for(int i = 0; i <=n; i++) {
	        dp[i][0] = 1;
	       // dp[0][i] = 0;
	    }
	    for(int i = 0; i <=num; i++) {
	       // dp[i][0] = 1;
	        dp[0][i] = 0;
	    }
	    for( int i = 1; i <= n; i++) {
	        for(int j = 1; j <=num; j++){
	            if(j < arr[i-1]){
	                dp[i][j] = dp[i-1][j];
	            } else {
	               dp[i][j] = dp[i-1][j] + dp[i][j-arr[i-1]];
	            }
	           // cout<<dp[i][j]<<",";
	        }
	       // cout<<endl;
	    }
	    cout<<dp[n][num]<<endl;
	}
	return 0;
}