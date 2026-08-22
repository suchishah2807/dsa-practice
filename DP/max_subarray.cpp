#include <bits/stdc++.h>
using namespace std;
int maxsubarray(vector<int> &arr){
    vector<int> pf(arr.size(),0);
    pf[0]=arr[0];
    for(int i=1;i<arr.size();i++){
        pf[i]=pf[i-1]+arr[i];
    }
    int max_sum=0;
    int min_sum=pf[0];
    for(int i=1;i<arr.size();i++){
        if(pf[i]<min_sum){
            min_sum=pf[i];
        }
        else{
            max_sum=max(max_sum,pf[i]-min_sum);
        }
    }
    return max_sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}