#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int k;
    cin>>k;
    vector <int> arr(n);
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr[i]=num;
    }
    // [2,1,7,4,8,9,5] size=7
    vector <int> pf_sum(n+1);
    pf_sum[0]=0;
    for(int i=1;i<n+1;i++){
        pf_sum[i]=arr[i-1]+pf_sum[i-1];
    }
    // [0,2,3,10,14,22,31,36] size=8
    
    int maxsum=INT_MIN;
    // n=7, k=3
    // right-left+1=k
    for(int left=0;left<=n-k+1;left++){
        int right=left-1+k;
        
        int sum=pf_sum[right+1]-pf_sum[left];
        maxsum=max(maxsum,sum);
    }
    // r=2 l=0 pf_sum[3]-pf_sum[0]=10-0=10 ->sum=10
    // r=3 l=1 pf_sum[4]-pf_sum[1]=14-2=12 ->sum=12
    // .
    // .
    // r=6 l=4 pf_sum[6]-pf_sum[4]=31-14=17
    // r=7 l=5 pf_sum[7]-pf_sum[5]=36-22=14
    return 0;
}