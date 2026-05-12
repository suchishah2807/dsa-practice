#include <bits/stdc++.h>
using namespace std;
// brute force O(n^2) time O(1) space
vector <int> two_sum1(vector <int> &nums, int target){
    vector <int> ans;
    int n = nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                return ans;
            }
        }
    }
    return ans;
}
// sorting and two pointer O(n long n) time O(1) space
vector <int> two_sum2(vector <int> &nums, int target){
    sort(nums.begin(),nums.end());
    vector <int> ans;
    int left = 0;
    int right = nums.size()-1;
    while(left<right){
        if(nums[left] + nums[right]==target){
            ans.push_back(nums[left]);
            ans.push_back(nums[right]);
            return ans;
        }
        else if(nums[left] + nums[right] > target){
            right--;
        }
        else{
            left++;
        }
    }
    return ans;
}
// hashmap
vector <int> two_sum3(vector <int> &nums, int target){
    unordered_set <int> s;
    vector <int> ans;
    for(int i=0;i<nums.size();i++){
        int complement = target - nums[i];
        if(s.find(complement)!=s.end()){
            auto it = s.find(complement);
            ans.push_back(nums[i]);
            ans.push_back(*it);
            return ans;
        }
        s.insert(nums[i]);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}