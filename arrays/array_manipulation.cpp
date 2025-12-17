#include <iostream>
using namespace std;
const int N=1e7+10;
long long int a[N];

int main(){
    int n,q;
    cin>>n>>q;
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        a[l]+=k;
        a[r+1]-=k;
    }
    for(int i=1;i<=n;++i){
        a[i]+=a[i-1];
    }
    long long mx=-1;
    for(int j=1;j<=n;++j){
        if(a[j]>mx){
            mx=a[j];
        }
    }
    cout<<mx;
}
