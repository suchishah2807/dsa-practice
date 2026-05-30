#include <bits/stdc++.h>
using namespace std;
// maximum subarray problem is equivalent to buy and sell stock
// sum of subarray [i+1,...j] = prefixsum[j]-prefixsum[i]
// we want to maximise the j sum and minimise the i sum i.e maximise sell minimum buy to get maximum profit(sum here) 
int maxSubArray(vector<int>& nums) {
    //eg. nums = [-2,1,-3,4,-1,2,1,-5,4]
    int min = 0;        // prefix sum starts at 0
    int maxsum = nums[0];  // handles all-negative case
    int pf = 0;

    for (int num : nums) {
        pf += num;                              // build prefix sum
        maxsum = max(maxsum, pf - min);   // sell - buy
        if (pf < min)
            min = pf;                           // reset buy to lowest
    }
    return maxsum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}