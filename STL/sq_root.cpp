#include <bits/stdc++.h>
using namespace std;
double eps=1e-6;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double n;
    cin>>n;
    double low=1,high=n,mid;
    while(high-low>eps){
        mid=(high+low)/2;
        if(mid*mid<n){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    cout<<low<<endl;
    cout<<high<<endl;

    return 0;
}