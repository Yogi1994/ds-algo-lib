/**
https://practice.geeksforgeeks.org/problems/maximum-product-cutting/0/
**/
#include <iostream>
using namespace std;

long long int modu = 1000000007;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    long long int ans = 1;
	    while(n > 4){
	        ans=(ans*3)%modu;
	        n-=3;
	    }
	    cout<<(ans*n)%modu<<endl;
	    
	}
	return 0;
}