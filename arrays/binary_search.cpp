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
int target;
cin>>target;
int low=0;
int high=n-1;
while(low<=high){
    int mid=(low+high)/2;
    if(nums[mid]==target){
        cout<<"Target is at "<<mid<<" index"<<endl;
        break;
    }
    if(target>nums[mid]){
        low=mid+1;
    }
    else if(target<nums[mid]){
        high=mid-1;
    }
   
    else{
        cout<<"Not found";
    }
}

    return 0;
}