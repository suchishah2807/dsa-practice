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
    queue <int> neg_nums;
    vector <int> ans;
    int i=0,j=0;
    while(j<n){
        if(nums[j]<0){
            neg_nums.push(nums[j]);
        }
        if(j-i+1==k){
            if(neg_nums.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(neg_nums.front());
            }
        }

        if(!neg_nums.empty() && nums[i]==neg_nums.front()){
            neg_nums.pop();
        }
        i++;
        j++;
    }
    

    return 0;
}