#include<iostream>
#include<cmath>
#include<vector>


using namespace std;


int getSumUtil(int *st, int ss, int se, int qs, int qe, int si) {
 	if (qs <= ss && qe >= se) 
        return st[si]; 

	if (se < qs || ss > qe)
		return 0;

	int mid = ss + (se-ss)/2;

	return getSumUtil(st, ss, mid, qs, qe, si*2+1)+
		getSumUtil(st, mid+1, se, qs, qe, si*2+2); 
}

int getSum(int *st, int n, int qs, int qe) {

	if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout<<"Invalid Input";
        return -1;
    }
	return getSumUtil(st, 0, n-1, qs, qe, 0);
}


void updateValueUtil(int *st, int si, int ss, int se, int diff, int i){
	if( i < ss || i > se){
		return;
	}
	st[si] = st[si] + diff;
	if(se!=ss) {
		int mid = ss + (se-ss)/2;
		updateValueUtil(st, si*2+1, ss, mid, diff, i);
		updateValueUtil(st, si*2+2, mid+1, se, diff, i);
	}
}

void updateValue(int *st, int arr[], int n, int val, int i) {
	if(i < 0 || i > n-1) {
		cout<<"Invalid Input";
        return;
	}
	int diff = val - arr[i];
	arr[i] = arr[i]+diff;
	updateValueUtil(st, 0, 0, n-1, diff, i);
}

int constructUtil(int *st, int si, int arr[], int arr_s, int arr_e ) {
	if(arr_s == arr_e){
		st[si] = arr[arr_s];
		return arr[arr_s];
	}
	int mid = arr_s + (arr_e - arr_s)/2;
	st[si] = constructUtil(st, si*2+1, arr, arr_s, mid) +
			constructUtil(st, si*2+2, arr, mid+1, arr_e);

	return st[si];
}

int *constructST(int arr[], int n ) {

	
	int h = (int)(ceil(log2(n))); // height of tree 
	int st_size = 2*(int)pow(2, h) - 1; 
	int *st = new int[st_size]; 
	constructUtil(st, 0, arr, 0, n-1);
	return st;
}

int main() {
	int arr[] =  {1, 2,3,4,5}; 
	int n = sizeof(arr)/sizeof(arr[0]);
	int *st = constructST(arr, n);

	cout<<getSum(st, n, 1,3)<<endl;

	updateValue(st, arr, n, 6, 4);


	cout<<getSum(st, n, 0,4);


	return 0;
}