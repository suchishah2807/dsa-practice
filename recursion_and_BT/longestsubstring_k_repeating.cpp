#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k) {
    if(s.length()==0) return 0;
    vector <int> hsh(26);
    for(int i=0;i<s.length();i++){
        hsh[s[i]-'a']++;
    }
    for(int i=0;i<s.length();i++){
        if(hsh[s[i]-'a']<k){
        int left  = longestSubstring(s.substr(0, i), k);
        int right = longestSubstring(s.substr(i+1), k);
        return max(left, right);
        }
    }
    return s.length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}