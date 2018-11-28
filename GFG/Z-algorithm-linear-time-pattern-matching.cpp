/** Z algorithm - pattern matching in linear time */

#include<iostream>

using namespace std;


void calculateZArr(string combine, int z[]) {
	
	int l = -1, h = -1;
	for( int i = 1; i < combine.length(); i++) {
		int matchCount = 0;
		for( int ci = 0; ((i + ci) < combine.length()) && combine[ci] == combine[ci+i]; ci++){
			matchCount++;
		}
		if(matchCount > 0){
			z[i] = matchCount;
			int h = i + matchCount -1 ;
			for(int j = 1; j < matchCount && i < combine.length(); j++, i++) {
				if( i + z[j] < h) {
					z[i+1] = z[j];
				} else{
					i--;
					break;
				}
			}
		}
	}
}

void search(string s, string pattern){
	string combine = pattern+ "$" + s;
	// string combine = "aabxaabxcaabxaabxay";//pattern+ "$" + s;
	int z[combine.length()] ={0};
	calculateZArr(combine, z);
	
	cout<<"pattern found at  index(s): ";

	for(int i = 0; i < combine.length(); i++){
		if(pattern.length() == z[i]){
			cout<<i - pattern.length() -1 <<",";
		}
	}
}


int main() {


	// string s ="xabcabzabc", pattern = "abc";
	string s, pattern ;
	cin>>s>>pattern;
	
	search(s, pattern);

	return 0;
}