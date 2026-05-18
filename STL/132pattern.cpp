#include <bits/stdc++.h>
using namespace std;
// find if there exist pattern like nums[i]<nums[k]<nums[j] for i<j<k
bool find132pattern(vector<int>& nums) {
    stack <pair<int,int>> st;
    int minimum = nums[0];
    for(int i=1;i<nums.size();i++){
        // make sure the top of stack it always the greatest element i.e nums[j]
        while(!st.empty() && st.top().first<=nums[i]) {
            st.pop();
        }
        if(!st.empty() && nums[i]>st.top().second) return true;
        st.push({nums[i],minimum});
        minimum = min(minimum,nums[i]);
    }
    return false;        
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> nums = {3,1,4,2};
    bool ans = find132pattern(nums);
    cout<<ans;
    return 0;
}