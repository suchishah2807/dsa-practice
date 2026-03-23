#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        map <int,vector<int>> rev_count;
        for(auto &pair : count){
            rev_count[pair.second].push_back(pair.first);
        }
        vector <int> result;
        auto it = rev_count.rbegin();
        for (int i = 0; i < k && it != rev_count.rend();i++, ++it)
            for(int num : it->second){
                if (result.size() == k) break;                  
                result.push_back(num);
            }
        return result;
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin>>k;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums[i]=num;
    }
    Solution sol;

    vector<int> result = sol.topKFrequent(nums, k);

    for (int x : result)
        cout << x << " ";
    cout << endl;


    return 0;
}