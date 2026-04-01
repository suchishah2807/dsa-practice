#include <bits/stdc++.h>
using namespace std;
// this q find number with maximum frequency in array in O(n) time and *O(n) space*.
// ofc we can normally solve using maps and counting in O(n) time but space would be O(n) too
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;

        for (int num : nums) {
            if (count == 0)
                candidate = num;   // fresh candidate
            
            if (num == candidate)
                count++;
            else
                count--;           // cancel out
        }
        return candidate;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector <int> nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    Solution sol;
    int ans= sol.majorityElement(nums);
    cout<<ans;

    return 0;
}