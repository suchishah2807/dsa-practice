#include <bits/stdc++.h>
using namespace std;

    void solve(vector<int>& candidates, int index, int target, vector<vector<int>>& ans, vector<int>& soln){
        if(target == 0){
            ans.push_back(soln);
            return;
        }
        if(index == candidates.size()) return;
        
        for(int i = index; i < candidates.size(); i++){
            if(candidates[i] > target) break;
            if(i > index && candidates[i] == candidates[i-1]) continue;
            soln.push_back(candidates[i]);
            solve(candidates, i+1, target-candidates[i], ans, soln);
            soln.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> soln;
        solve(candidates, 0, target, ans, soln);
        return ans;
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int target = 8;
vector<vector<int>> res = combinationSum2({10,1,2,7,6,1,5},target);
        for(auto soln : res){
        for(auto num : soln){
            cout<<num<<" ";
        }
        cout<<endl;
    }


    return 0;
}