#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>>& ans, vector<int>&nums,int index){
    if(index==0){
        ans.push_back({nums[0]});
        return;
    }
    solve(ans,nums,index-1);
    int val = nums[index];
    vector<vector<int>> newAns;
    for(auto perm : ans){
        vector<int> newPerm;
        for(int i=0;i<=perm.size();i++){
            if(i==perm.size() || perm[i]!=val){
                vector<int> newPerm = perm;
                newPerm.insert(newPerm.begin()+i, val);
                newAns.push_back(newPerm);
            }

            if(i<perm.size() && perm[i]==val){
                newPerm.insert(newPerm.begin()+i,val);
                newAns.push_back(newPerm);
                break;
            }
        }
    }
    ans=newAns;
}
vector<vector<int>> permutationsDuplicates(vector<int>nums){
    vector<vector<int>> ans;
    solve(ans,nums,nums.size());
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}