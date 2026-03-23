#include <bits/stdc++.h>
using namespace std;
// 2 3 4 6 7 8
int lower_bound(vector <int> &v, int element){
    int low=0;
    int high=v.size()-1;
    int mid;
    while(high-low>1){
        mid=(high+low)/2;
        if(v[mid]<element){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    if(v[low]>=element){
        return low;
    }
    if(v[high]>=element){
        return high;
    }
    else{
        return -1;
    }
}
int higher_bound(vector <int> &v,int element){
    int low=0;
    int high=v.size()-1;
    int mid;
    while(high-low>1){
        mid=(high+low)/2;
        if(v[mid]<=element){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    if(v[low]>element){
        return low;
    }
    if(v[high]>element){
        return high;
    }
    else{
        return -1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int element;
    cin>>element;
    cout<<lower_bound(v,element);
    

    return 0;
}