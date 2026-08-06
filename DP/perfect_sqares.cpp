#include <bits/stdc++.h>
using namespace std;

int helper(int n, unordered_map<int,int>& memo){
    if(n == 0) return 0;
    if(memo.count(n)) return memo[n];
    
    int min_squares = INT_MAX;
    for(int i=1; i*i<=n; i++){
        int sub = helper(n - i*i, memo);
        min_squares = min(min_squares, 1+sub);
    }
    return memo[n] = min_squares;
}

int numSquares(int n){
    unordered_map<int,int> memo;
    return helper(n, memo);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}