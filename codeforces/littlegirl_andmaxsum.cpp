#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;
    vector <long long> nums(n+2);
    vector <long long> count(n+2);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    
    while(q--){
        int l,r;
        cin>>l>>r;
        
            count[l]++;
            count[r+1]--;
        
    }
    vector<long long>sum(n+1);
    //prefix sum, because i cant afford O(n^2) so add count to l index and subtract 1 from r-1 index
    //as we do prefix sum it adds count from l to r and resets r-1th index to its orignal index by subtracting 1.
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+count[i];
    }
   
    //sorted in ascending order
    sort(nums.begin()+1,nums.end(),greater<int>());
    sort(sum.begin()+1,sum.end(),greater<int>());
    long long result=0;
    for(int i=1;i<=n;i++){
        result=result + (sum[i]*nums[i]);
    }
    cout<<result;
    return 0;
}