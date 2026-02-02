#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector <int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    unordered_map<int,int> freq;
            freq[0] = 1;
            int pf_sum = 0;
            int count = 0;
            for (int x : nums) {
                pf_sum += x;
                int check = pf_sum - k;
                if (freq.count(check)) {
                    count += freq[check];
                }

                freq[pf_sum]++;
            }
    cout<< count;
    return 0;
}