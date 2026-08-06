#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& nums, unordered_map<int,int>&memo, int i){
    if(i>=nums.size()) return 0;
    if(!memo.count(i)){
        memo[i] = max(helper(nums,memo,i+1), nums[i] + helper(nums,memo,i+2));
    }
    return memo[i];
}
int rob(vector<int>& nums) {
    unordered_map<int,int> memo;
    return helper(nums, memo, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}