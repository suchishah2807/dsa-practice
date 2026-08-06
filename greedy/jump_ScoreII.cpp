#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int near,far,jumps=0;
    while(far<nums.size()-1){
        int farthest=0;
        for(int i =near;i<=far;i++){
            farthest = max(farthest,i+nums[i]);
        }
        near = far+1;
        far = farthest;
        jumps++;
    }
    return jumps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}