#include <bits/stdc++.h>
using namespace std;

    void solve(vector<int>& candidates, int index, int target, vector<vector<int>>& ans, vector<int>& soln){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(soln);
            }
            return;
        }
        if(candidates[index]<=target){
            soln.push_back(candidates[index]);
            solve(candidates,index,target-candidates[index],ans,soln);
            soln.pop_back();
        }
        solve(candidates,index+1,target,ans,soln);
    }
    vector<vector<int>> combinationSum(vector<int> candidates, int target) {
        vector<vector<int>> ans;
        vector<int> empty;
        solve(candidates, 0, target, ans, empty);
        return ans;
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int target = 7;
    vector<vector<int>> res = combinationSum({2,3,6,7},target);
    for(auto soln : res){
        for(auto num : soln){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    

    return 0;
}