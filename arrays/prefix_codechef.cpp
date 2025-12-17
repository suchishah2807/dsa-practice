//Brute force method
// #include <iostream>
// using namespace std;
// int gcd(int a,int b){
//     if(b==0){
//         return a;
//     }
//     else{
//         return gcd(b,a%b);
//     }
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n,q;
//         int a[n];
//         cin>>n>>q;
//         for(int i=1;i<=n;i++){
//             cin>>a[i];
//         }
//         while(q--){
//             int l,r;
//             cin>>l>>r;
//             int gc=0;
//             for(int x=1;x<l;x++){
//                 gc=gcd(gc,a[x]);
//             }
//             for(int y=r+1;y<=n;y++){
//                 gc=gcd(gc,a[y]);
//             }
//             cout<<gc<<endl;

//         }
//     }
// }
#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int a[n+10],forward[n+10],backward[n+10];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            forward[i]=gcd(forward[i=1],a[i]);
        }
        for(int i=n;i>0;i--){
            backward[i]=gcd(backward[i+1],a[i]);
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            cout<<gcd(forward[l-1],backward[r+1]);
        }
    }
}