#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;
    vector <int> nums(n+1);
    vector <int> count(n+1);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    
    while(q--){
        int l,r;
        cin>>l>>r;
        for(int i=l;i<=r;i++){
            count[l]++;
            count[r+1]--;
        }
    }
    vector<int>sum(n+1);
    //prefix sum, because i cant afford O(n^2) so add count to l index and subtract 1 from r-1 index
    //as we do prefix sum it adds count from l to r and resets r-1th index to its orignal index by subtracting 1.
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+count[i];
    }
    vector<int> new_nums(n+1);
    sort(nums.begin()+1,nums.end(),greater<int>());
    sort(count.begin()+1,count.end(),greater<int>());
    for(int i=1;i<=n;i++){

    }
    return 0;
}