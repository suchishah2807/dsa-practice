#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector <int> nums(n);
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums[i]=num;
    }
    // 4 1 1 1 2 3 5
    // k=5
    int i=0,j=0;
    int max_size=INT_MIN;
    int sum=nums[0];
    while(j<n){
        if(sum==k){
            int size=j-i+1;
            max_size=max(size,max_size);
            j++;
            sum=sum+nums[j]-nums[i];
            i++;
        }
        else if(sum<k){
            j++;
            if(j<n){
            sum=sum+nums[j];
            }
        }
        else if(sum>k){
            sum=sum-nums[i];
            i++;
        }       
    }

    return 0;
}