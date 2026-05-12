#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
int n = nums.size();
        vector<int> left_arr(n+1);
        vector<int> right_arr(n+1);

        // your left logic — unchanged
        left_arr[0] = 1;
        left_arr[1] = nums[0];
        for (int i = 2; i < n+1; i++)
            left_arr[i] = left_arr[i-1] * nums[i-1];

        // your right logic — just replace -i with n-i+1
        right_arr[n]   = 1;           // was right_arr[-1]
        right_arr[n-1] = nums[n-1];   // was right_arr[-2]
        for (int i = 2; i < n+1; i++)
            right_arr[n-i] = right_arr[n-i+1] * nums[n-i];

        // result — unchanged
        vector<int> result(n);
        for (int i = 0; i < n; i++)
            result[i] = left_arr[i] * right_arr[i+1];

        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}