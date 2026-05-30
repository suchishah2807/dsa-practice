#include <bits/stdc++.h>
using namespace std;

    void solve(vector <vector<int>>& ans, vector<int>& soln, int k, int n, int start){
        if(soln.size()==k && n==0){
            ans.push_back(soln);
            return;
        }
        if(soln.size()==k || n==0) return;
        for(int i=start;i<10;i++){
            if(i>n) break; // we cant add numbers greater than target
            soln.push_back(i);
            solve(ans, soln, k, n-i, i+1);
            soln.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <vector<int>> ans;
        vector<int> soln;
        solve(ans,soln,k,n,1);
        return ans;
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> res = combinationSum3(3,7);
    for(auto soln : res){
        for(auto num : soln){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}