#include <bits/stdc++.h>
using namespace std;
const int N=150;
int hsh[N];
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        char chr=s[i];
        int ascii_value=(int)chr;
        hsh[ascii_value]++;
    }
    bool is_double= false;
    for(int j=0;j<150;j++){
        if(hsh[j]==0){
            continue;
        }
        else if(hsh[j]%2==0){
            is_double=true;
            cout<<"Yes";
            break;
        }
    }
    if (is_double==false){
        cout<<"No";
    }
}