#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int i=-1;
    int j=-1;
    for(int k=0;k<nums.size()-1;k++){
        if(nums[k]<nums[k+1]) i=k;
    }
    
    for(int k=i;k<nums.size();k++){
        if(nums[k]>nums[i]) j=k;
    }
    if(i == -1){
        sort(nums.begin(), nums.end());
        return;
    }

    else {swap(nums[i],nums[j]);
    reverse(nums.begin()+i+1,nums.end());}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	vector<int> nums = {1,3,2};
    nextPermutation(nums);

    

    return 0;
}