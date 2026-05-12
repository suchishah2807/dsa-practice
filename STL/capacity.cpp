#include <bits/stdc++.h>
using namespace std;
bool checkIfPartitionPossible(vector<int>& weights, int days, int mid){
        int partitionsAvailable = days;
        int sumCapacityLoadedInShip = 0;
        int i = 0;
        while(i < weights.size()){
            if(partitionsAvailable<=0) return false;
            if (weights[i] + sumCapacityLoadedInShip <= mid){
                sumCapacityLoadedInShip += weights[i];
                i++;
            }else{
                partitionsAvailable--;
                sumCapacityLoadedInShip = 0;
            }
        }
        if (partitionsAvailable >= 0){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // range between min = max(weights) max = sum(weights)
        int sum = 0;
        int mx = INT_MIN;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            mx = max(mx,weights[i]);
        }
        int l = mx;
        int r = sum;
        // binary search->on answers
        // need to check if sum of weights on each day is less than weight capacity(i.e mid here)
        int ans;
        while(l<=r){
            int mid = (l+r)/2;
            bool isPossible = checkIfPartitionPossible(weights,days,mid);
            if (isPossible){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    bool ans = checkIfPartitionPossible(nums,5,11);
    cout<<ans;
    return 0;
}