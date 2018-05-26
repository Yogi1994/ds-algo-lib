/**
https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/
*/
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i =0 ; i < n; i++){
	        cin>>arr[i];
	    }
	    int dp[n];
	    for(int i =0 ; i <n; i++){
	            dp[i]=arr[i];
	    }
	    for(int i = 1; i <n ; i++){
	        for(int j = 0; j < i; j++) {
	            if(arr[i] > arr[j] && dp[i] < dp[j] +arr[i])
	                dp[i] = dp[j] + arr[i];
	        }
	    }
	    int ans = 0;
	    for(int i = 0; i <n ; i++)
	        ans = max(dp[i], ans);
	    cout<<ans<<endl;
	}
	return 0;
}