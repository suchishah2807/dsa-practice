#include <bits/stdc++.h>
using namespace std;

void generate(vector<int> &subset, int i, vector<int> &nums) {
    if (i == nums.size()) {
        // one complete subset formed
        for (int x : subset) 
        {
            cout << x << " ";
        }
        cout << "\n";
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

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> subset;
    generate(subset, 0, nums);

    return 0;
}
