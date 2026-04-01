#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // sort by start
        vector<vector<int>> result;

        for (auto it = intervals.begin(); it != intervals.end(); it++) {
            if (it+1 != intervals.end() && (*it)[1] >= (*(it+1))[0]) {
                // overlap — merge and skip next
                vector<int> merged = {(*it)[0], max((*it)[1], (*(it+1))[1])};
                result.push_back(merged);
                it++;  // skip next since it's consumed
            } else {
                result.push_back(*it);  // no overlap, push as is
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    Solution sol;
    vector<vector<int>> result=sol.merge(intervals);
    for(auto& interval : intervals){
        cout<<interval[0]<<","<<interval[1]<<" ";
    }

    return 0;
}