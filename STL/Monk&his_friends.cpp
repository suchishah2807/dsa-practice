#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        unordered_set <long long> students;
        for(int i=0;i<n+m;i++){
            long long x;
            cin>>x;
            if(i<n){
                students.insert(x);
            }
            else if(i>=n && i<n+m){
                if(students.find(x)!=students.end()){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
                students.insert(x);
            }
        }

    }
}
//10*(2*10^5())