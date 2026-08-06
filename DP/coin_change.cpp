#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& coins, int amount, vector<int>& memo){
    if(amount == 0) return 0;
    if(amount < 0) return INT_MAX;
    if(memo[amount] != -1) return memo[amount];

    int min_num = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int sub = helper(coins, amount-coins[i], memo);
        if(sub != INT_MAX){
            min_num = min(min_num, 1+sub);
        }
    }
    return memo[amount] = min_num;
}

int coinChange(vector<int>& coins, int amount){
    vector<int> memo(amount+1, -1);
    int ans = helper(coins, amount, memo);
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}