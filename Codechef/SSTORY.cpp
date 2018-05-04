#include<iostream>
#include<cmath>
#include<map>
#include<unordered_map>
using namespace std;


string a,b;
long multi = 1009;
long modu = 1000003;

long long power(long a, long n) {
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return a;
    }
    long long b = (a*a) %modu;
    if(n%2 == 1) {
        return (power(b, n/2) * a ) %modu;
    } else {
        return power(b, n/2)%modu;
    }
}


int possible(int len) {
    unordered_map<long, int> hm2;
    long hash1=0, hash2 = 0;
    for(int i = 0; i < len; i++) {
        hash2 = (hash2*multi + b[i] +modu )%modu;
        hash1 = (hash1*multi + a[i] +modu )%modu;
    }
    
    hm2[hash2] = 0;
    long long d = 1;
    for (int i = 0; i < len-1; i++)
        d = (d*multi)%modu;
    for(int i = len; i < b.length(); i++) {
        hash2 = (multi*(hash2 - ((b[i-len]*d)%modu) + modu) + b[i])%modu;
        hm2[hash2] = i - len + 1;
    }

    if(hm2.find(hash1) != hm2.end()) {
        if(a.substr(0, len) == b.substr(hm2[hash1], len))
            return 0;
    }
    int index = -1;
    for(int i = len; i < a.length(); i++) {
        hash1 = (multi*(hash1 - ((a[i-len]*d)%modu) + modu) + a[i])%modu;
        
        if(hm2.find(hash1) != hm2.end()) {
            if(a.substr(i-len+1, len) == b.substr(hm2[hash1], len)){
                if(index == -1) {
                    index = hm2[hash1];
                } else {
                    index = min(index, hm2[hash1]);
                }
            }
        }
    }
    return index;

}


int main() {
    
    cin>>a>>b;
    int len1 = a.length();
    int len2 = b.length();

    int lower = 0, upper = len2, mid;
    while(lower < upper){
        mid = (upper+ lower+1)/2;
        // cout<<mid<<";";
        if(possible(mid) != -1) {
            lower = mid;
            // cout<<";";
        } else {
            upper = mid - 1;
        }
    }
    int index = possible(lower);

    if(index != -1) {
        cout<<b.substr(index, lower);
        cout<<endl<<lower;
    } else {
        cout<<0;
    }

    return 0;
}