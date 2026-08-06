#include <bits/stdc++.h>
using namespace std;

int helper(unordered_map<int,int> &memo, int k){
    if(k==0) return 1;
    if(k<=0) return 0;
    if(!memo.count(k)) memo[k] = helper(memo,k-1) + helper(memo, k-2);
    return memo[k];
}
int climbingstairs(int n){
    unordered_map<int,int> memo;
    return helper(memo,n);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}