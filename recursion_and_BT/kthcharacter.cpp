#include <bits/stdc++.h>
using namespace std;

int kthGrammar(int n, int k) {
    if(n==1) return 0;
    int prevk = ceil((k+1)/2);
    bool even = true;
    if(k%2==1) even=false;
    int ans = kthGrammar(n-1,prevk);
    if(ans==0){
        if(even) return 1;
        else return 0;
    }
    else {
        if(even) return 0;
        else return 1;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}