#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
    }
    // if the sum is odd u cant split it into sum of 2 subarrays
    // if sum = S, for equal sum sum of subset should be S/2, which is not possible
    if(sum%2!=0) return false;
    int target = sum/2;
    set <int> sums;
    // make a set of of all possible subset sums
    sums.insert(0);
    // 0 is always possible -> dont pick any number
    for(int i=0; i<nums.size(); i++){
        set<int> temp = sums;
        // add current number to all existing sums to check if subset sum=target sum
        for(auto s : sums){
            int new_sum = s + nums[i];
            if(new_sum == target) return true;
            temp.insert(new_sum);
        }
        sums = temp;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}