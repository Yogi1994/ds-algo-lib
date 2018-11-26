#include<iostream>
#include<cmath> 

using namespace std;

int stree[1000] = {0};
int lazy[1000] = {0};


void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff){
    if (lazy[si] != 0) {
        stree[si] += (se-ss+1)*lazy[si];
        if (ss != se){ 
            lazy[si*2 + 1] += lazy[si];
            lazy[si*2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }

    if(ss > se || ss > ue || se < us){
        return;
    }
    if(ss <= us && se >= ue) {
        stree[si] += (se-ss+1)*diff;
        if(ss!=se){
            lazy[si*2+1] = diff;
            lazy[si*2+2] = diff;
        }
        return;
    }
    int mid = (se+ss)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);

    stree[si] = stree[si*2+1] + stree[si*2+2]; 

}

void updateRange(int n, int us, int ue, int diff){
    updateRangeUtil(0, 0, n-1, us, ue, diff);
}

int getSumUtil(int si, int ss, int se, int qs, int qe){
    // cout<<"getSumUtil"<<si<<";,"<<ss<<"-"<<se<<";"<<qs<<"-"<<qe<<endl;
    
    if(lazy[si]!=0){
        stree[si] += (se-ss+1)*lazy[si];
        if (ss != se){ 
            lazy[si*2 + 1] += lazy[si];
            lazy[si*2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>qe || se<qs) {
        return 0;
    }

    if(qs <= ss && qe >= se){
        return stree[si];
    }
    
    int mid = ss + (se-ss)/2 ;
    return getSumUtil(si*2 + 1, ss, mid, qs, qe ) +
        getSumUtil(si*2 + 2, mid+1, se, qs, qe);
}

int getSum(int n, int qs, int qe) {
    if (qs < 0 || qe > n-1 || qs > qe){
        cout<<"Invalid input";
        return -1;
    }
    return getSumUtil(0, 0, n-1, qs, qe);
}

void constructUtil(int si, int arr[], int ss, int se) {
    // cout<<"constructUtil"<<si<<";,"<<ss<<"-"<<se<<endl;
    if(se < ss)
        return;
    if(se == ss) {
        stree[si] = arr[se];
        return;
    }
    int mid = ss + (se-ss)/2;
    constructUtil(si*2+1, arr, ss, mid);
    constructUtil(si*2+2, arr, mid+1, se);
    stree[si] = stree[si*2+1]+stree[si*2+2];
}


void construct(int n, int arr[]) {
    
    constructUtil(0, arr, 0, n-1);
    // for(int i = 0; i < n; i++) {
    //  cout<<arr[i]<<";";
    // }
    // cout<<endl;
    // for(int i = 0; i < size_st; i++) {
    //  cout<<stree[i]<<";";
    // }
    // cout<<endl;
}


int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(int);
    construct(n, arr);

    cout<<getSum(n, 0, 3)<<endl;
    
    updateRange(n, 1, 5, 10); // (n, us, ue, diff)

    cout<<getSum(n, 0, 3)<<endl;

    return 0;
}