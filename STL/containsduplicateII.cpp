#include <bits/stdc++.h>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    int i=0;
    int j=0;
    unordered_map <int,int> mp;
    while(i<n && j<n){
        while(i<n && j<n && j-i<=k){
            mp[nums[j]]++;
            if(mp[nums[j]]>1) return true;
            j++;
        }
        mp[nums[i]]--;
        i++;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> nums = {1,2,3,1,2,3};
    bool ans = containsNearbyDuplicate(nums,2);
    cout<<ans;
    

    return 0;
}