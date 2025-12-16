#include <iostream>
using namespace std;
const int N=1e5+10;
int arr[N];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        arr[i] = arr[i-1] + num;
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<arr[r]-arr[l-1]<<endl; 
    }
}