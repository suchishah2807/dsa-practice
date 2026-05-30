#include <bits/stdc++.h>
using namespace std;
vector <vector<int>> subsets;
void generate(vector<int> &subset, int i, vector<int> &nums) {
    if (i == nums.size()) {
        subsets.push_back(subset);
        return;
    }

    // not include nums[i]
    generate(subset, i + 1, nums);

    // include nums[i]
    subset.push_back(nums[i]);
    generate(subset, i + 1, nums);
    subset.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums = {1,2,3};

    vector<int> empty;
    generate(empty, 0, nums);
    for(auto subset:subsets){
        for(auto ele:subset){
            cout<<ele<<" "; 
        }
        cout<<endl;
    }

    return 0;
}
