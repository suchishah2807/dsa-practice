#include <bits/stdc++.h>
using namespace std;


bool canJump(vector<int>& nums) {
    int goal = nums.size() - 1;
    // so basically we assume current position to be goal-1 position. and if maximum jump+current position>=goal then 
    // we can reach goal if we reach goal-1 so we change goal to goal-1 position. continuing this we hope to read goal position = 0
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (i + nums[i] >= goal) {
            goal = i;
        }
    }

    return goal == 0;        
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {2,3,1,1,4};
    cout<< canJump(nums);

    return 0;
}