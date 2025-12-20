#include <iostream>
using namespace std;

const int N=1e5+10;
int a[N];
void merge(int l,int r,int mid){
    int l_size=mid-l+1;
    int r_size=r-mid;
    int L[l_size+1]; //+1 is for INT_MAX
    int R[r_size+1];
    // lets say L= 1 4 7 9
    //          R= 2 6 8
    //as we compare L and R and place them, R finishing up first and 
    //we dont have anything to compare L with so we add INT_MAX as last index such that actual elemetns 
    //are always smaller 
    L[l_size]=R[r_size]=INT32_MAX;
    for(int i=0;i<l_size;i++){
        L[i]=a[i+l];
    }
    for(int i=0;i<r_size;i++){
        R[i]=a[i+mid+1];
    }
    int l_i=0;
    int r_i=0;
    for(int i=l;i<=r;i++){
        if(L[l_i]<R[r_i]){
            a[i]=L[l_i];
            l_i++;
        }
        else{
            a[i]=R[r_i];
            r_i++;
        }
    }
}
void mergesort(int l,int r){
    if (l==r){
        return;
    }
    int mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,r,mid);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}