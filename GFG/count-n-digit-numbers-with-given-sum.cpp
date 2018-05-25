/**
https://practice.geeksforgeeks.org/problems/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum/0/
**/
#include <iostream>
#include <cstring>
using namespace std;

int lookup[101][1001];
long modu = 1000000007;
long long int countNums(long n, long sum) {
    if(n == 0){
        return sum == 0;
    }
    if(lookup[n][sum] != -1){
        return lookup[n][sum];
    }
    long long ans = 0;
    for(int i = 0; i <= 9; i++) {
        if (sum-i >= 0)
            ans= (ans + countNums(n-1, sum-i))%modu;
    }
    return lookup[n][sum] = ans;;
}

int main() {
	//code
	memset(lookup, -1, sizeof lookup);
	int t;
	cin>>t;
	while(t--){
	    int n, s;
	    cin>>n>>s;
	    long long int ans = 0; 
	    for(int i = 1; i <= 9; i++) {
	        if (s-i >= 0)
	            ans= (ans + countNums(n-1, s-i))%modu;
	    }
	    if(ans !=0)
	        cout<<ans<<endl;
	    else
	        cout<<-1<<endl;
	    
	}
	return 0;
}