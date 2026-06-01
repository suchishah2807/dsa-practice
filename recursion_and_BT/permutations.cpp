#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& ans, vector<int>& nums, int index){
    if(index==0){
        ans.push_back({nums[0]});
        return;
    }
    solve(ans, nums, index-1);
    int val = nums[index];
    
    vector<vector<int>> newAns;  // collect new perms here
    for(auto perm : ans){        // ans is not modified now
        for(int i=0; i<=perm.size(); i++){  // <= not < to insert at end too
            vector<int> newPerm = perm;
            newPerm.insert(newPerm.begin() + i, val);
            newAns.push_back(newPerm);
        }
    }
    ans = newAns;  // replace old ans with new perms
}

vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans,nums, nums.size()-1);
        return ans;
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}