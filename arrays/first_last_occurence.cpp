#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector <int> nums(n);
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums[i]=num;
    }
    int target;
    cin>> target;
    // first occurence
    int first=-1;
    int l=0,r=n-1;
    while(left<=right){
        int mid=(l+r)/2;
        if(nums[mid]==target){
            first=mid;
            r=mid-1;
        }
        else if(nums[mid]>target){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    // last occurence
    int last=-1;
    l=0,r=n-1;
    while(left<=right){
        int mid=(l+r)/2;
        if(nums[mid]==target){
            last=mid;
            l=mid+1;
        }
        else if(nums[mid]>target){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<"First occurence: "<<first<<" "<<"Last occurence: "<<last;
    return 0;
}