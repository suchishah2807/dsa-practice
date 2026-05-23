#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int left = i+1;
        int right = nums.size()-1;
        while(left<right){
            if(nums[left]+nums[right]+nums[i] >0) right--;
            else if(nums[left]+nums[right]+nums[i] < 0) left++;
            else{
                vector <int> temp ={nums[i],nums[left],nums[right]};
                ans.push_back(temp);
                left++;
                while(left<right && nums[left]==nums[left-1]) left++;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> nums = {-1,0,1,2,-1,-4};
    
    

    return 0;
}