/**
https://practice.geeksforgeeks.org/problems/flip-bits/0/
**/
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
	    for(int i = 0; i < n; i++){
	        cin>>arr[i];
	    }
	    
	    int maxi =0;
	    int curr_max = 0;
	    int present_count = 0;
	    for( int i = 0; i < n; i++ ) {
	        if(arr[i] == 1){
	            present_count++;
	        }
	        int curr_val = (arr[i] == 1)? -1:1;
	        curr_max = max(curr_val, curr_max+curr_val);
	        maxi = max(maxi, curr_max);
	    }
	    
	    maxi = max(0, maxi);
	    cout<<present_count + maxi<<endl;
	}
	
	return 0;
}