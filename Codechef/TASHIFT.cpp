#include<iostream>

using namespace std;

int main() {
	
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;

	b = b + b;

	/* generate the lps of b */
	int lps[n];
	lps[0] = 0;
	int len = 0, i = 1;
	while( i < n) {
		if(a[i] == a[len]){
			lps[i++] = ++len;
		} else if(len != 0) {
			len = lps[len-1];
		} else {
			lps[i++] = 0;
		}
	}

	/* Now find the answer */
	int m = n; // original length of a;
	n = 2*n; // for length of b;
	int maxlen = 0, curr = 0, ans = 0;
	int j = 0;
	i = 0;
	while( i < n) {
		if(a[j] == b[i]) {
			i++;
			j++;
			curr++;
			if(curr > maxlen) {
				maxlen = curr;
				ans = i - j; // Number of shifts
			}
			if( j == m) {
				break;
			}
		} else {
			curr = 0;
			if(j != 0) {
				j = lps[j-1];
			} else {
				i++;
			}
		}
	}
	cout<<ans;



	return 0;
}