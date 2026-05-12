#include <bits/stdc++.h>
using namespace std;

int totalhours(vector <int> &arr, int k){
    int total = 0;
    for(auto pile : arr){
        total+=ceil(pile/k);
    }
    return total;
}
int eatingrate(vector <int> &arr, int h){
    int ans=INT_MAX;
    int mx=INT_MIN;
    for(int i=0;i<arr.size();i++){
        mx=max(mx,arr[i]);
    }
    int l=1;
    int r=mx;
    while(l<=r){
        int mid = (l+r)/2;
        if(totalhours(arr,mid)>h) l=mid+1;
        else{
            ans=mid;
            r=mid-1;;
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}