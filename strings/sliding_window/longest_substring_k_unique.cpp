#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    int k;
    cin>>k;
    unordered_map <char,int> ch;
    int n=s.length();
    int i=0,j=0;
    int max_size=INT_MIN;
    while(j<n){
        ch[s[j]]++;
        if(ch.size()==k){
            int size=j-i+1;
            max_size=max(size,max_size);
            j++;
        }
        else if(ch.size()>k){
            while(ch.size()>k){
            ch[s[i]]--;
                if(ch[s[i]]==0){
                    ch.erase(s[i]);
                }
            i++;
        }
    }
        j++;
    }

    return 0;
}