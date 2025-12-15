#include <iostream>
using namespace std;
const int N=1e7+10;
int hsh[N];

int main(){
    int n;
    cin >>n;
    int a[n];
    for(int i=0;i<n;++i){
        cin >> a[i];
        hsh[a[i]]++;
    }
    int q;
    cin>>q;
    for(int j=0;j<q;++j)
    {
        int k;
        cin>>k;
        cout<<hsh[k]<<endl;
    }
}