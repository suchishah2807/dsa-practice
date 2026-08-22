#include <bits/stdc++.h>
using namespace std;
// leetcode 283
void moveZeroes(vector<int>& nums) {
    int left=0;
    int right=0;
    while(right<nums.size()){
        if(nums[right]!=0){
            swap(nums[left],nums[right]);
            left++;
        }
        right++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}