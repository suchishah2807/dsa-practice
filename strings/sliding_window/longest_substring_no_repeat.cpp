#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    unordered_map <char,int> freq;
    int n=s.length();
    int i=0,j=0;
    int max_size=0;
    while(j<n){
        freq[s[j]]++;
        if(freq[s[j]]==1){
            int size=j-i+1;
            max_size=max(max_size,size);
        }
        else if(freq[s[j]]>1){
            while(freq[s[j]]>1){
                freq[s[i]]--;
                i++;
            }
        }
        j++;
    }
    

    return 0;
}