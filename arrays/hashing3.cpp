#include <iostream>
using namespace std;
const int N=1e5+10;
int hsh[N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        hsh[num]=1;
    }
    for(int j=0;j<m;j++){
        int num2;
        cin>>num2;
        if(hsh[num2]==0){
            continue;
        }
        else{
            hsh[num2]++;
        }
    }
    for(int k=0;k<N;k++){
        if(hsh[k]==1){
            cout<<k<<endl;
        }
    }
}